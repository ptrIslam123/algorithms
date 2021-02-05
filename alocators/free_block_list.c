#include <string.h>

#include "heder/free_block_list.h"
#include "heder/test.h"

//#define _LOG_DEBUG_

#ifndef _LOG_DEBUG_
            
int count_reused = 0, count_new_alloc = 0;

#endif // !_LOG_DEBUG_


/*
    Аллокатор основан на списке свободных блоков 
    памяти которые мы переиспользуем при каждом(почти каждом) 
    высове функции аллокации.

     в начале наш список свободных блоков пуст. При первом запросе
     памяти мы выделяем запрашиваемый размер + размер для информационной
     структуры данных. Данную структуру мы заполняем метаинформацией,
     которую мы будем использовать для правильного периспользования
     блоков памяти. Каждый выделяемый блок облодает иформацией о размере
     самого блока и его статусе {0 - используется, 1 - свободен}.
     После использования выделенный блок будет удален (освобожден)
     пользовательем с помощу функции deallocate которая помечает блок как не используемый
     и помещает его в список свободных блоков для дальнейшего переиспользования.

     После первого вызова allocate последующие вызоввы прежде чем просить
     выделять в куче новые куски памяти мы будем искать подходящий по 
     размерам куски памяти в списке свободных блоков, если подходящего по размеру там не окажется,
     мы будем вынуждены алоцировать память в heap`е.  
*/

void*   
allocate(size_t size)
{
    size_t total_size       = size + SIZE_INODE_STRUCT;
    inode_t* new_inode      = alloc_inode(total_size);

    new_inode->size_block   = size;
    new_inode->is_free      = _IS_NOT_FREE_BLOCK;

    void* user_mem_block    = ((void*)new_inode) + SIZE_INODE_STRUCT;

    return user_mem_block;
}

void    
deallocate(void* free_block)
{
    inode_t* p_inode = (struct inode*)(free_block - SIZE_INODE_STRUCT);

    p_inode->is_free = _IS_FREE_BLOCK;
    add_inode_to_free_list(get_free_list_struct(), p_inode);
}




#define is_not_empty(list) (is_empty(list) < 0)

struct inode*           
alloc_inode(size_t total_size)
{
    free_list_t* list = get_free_list_struct();
    inode_t* result = NULL;

    /* если наш список не пуст */
    if (is_not_empty(list))
    {
        result = get_suitable_free_block(list, total_size);

        /* если среди свобожный блоков нашелся подходящий блок */
        if (result != NULL)
        {
#ifndef _LOG_DEBUG_
            write_log("REUSED_MEM_BLOCK\n");
            count_reused++;
#endif // !_LOG_DEBUG_
            return result;
        }
        else
        {
#ifndef _LOG_DEBUG_
            write_log("ALLOCATION_NEW_MEM_BLOCK\n");
            count_new_alloc++;
#endif // !_LOG_DEBUG_

            /* если не смогли найти подходящий свободный блок,
                то выделяем в heap`е новый блок памяти */
            return make_inode(total_size);
        }
    }
    else
    {

#ifndef _LOG_DEBUG_
            write_log("ALLOCATION_NEW_MEM_BLOCK\n");
            count_new_alloc++;
#endif // !_LOG_DEBUG_

        return make_inode(total_size);   
    }
}



struct free_block_list* 
get_free_list_struct()
{
    static unsigned char is_init = 0;
    static struct free_block_list* g_free_list = NULL;

    if (is_init == 0)
    {
        is_init = 1;
        g_free_list = make_free_list();
    }
    return g_free_list;
}

/*

    Метод пойска подходящего по размеру блока памяти
    в списке свободных блоков. Данный алгоритм просто начиная с начала
    перебирает последовательно все блоки памяти в списке, при этом ищем 
    блок подходящего размера (need_size >= current_size_block).

    Данный пойск линейный ,т.е имеет линейную алгоритмическую 
    сложность O(n), т.к. нам необходимо передрать последовательно список 
    пока не встретим подходящий по размеру блок (в худшем случае нам придется
    перебрать весь список и даже так не факт что найдем подходящий).
    Данный подход можно былобы улучшить отсортировав весь список по убыванию(
    по размеру свободных блоков). Например можно было бы использовать вместо 
    связанного списка бинарное дерево (еще лучше сбалансированное дерево),
    которое хранилобы блоки в отсортированном виде, тогда бы алгоритмическая 
    сложность была бы логарифмической, но структуру данных дерево мы пока не
    будем использовать!

*/

struct inode*           
get_suitable_free_block(struct free_block_list* list, size_t need_size)
{
    inode_t* item = list->begin;
    
    /* здесь потенциальное зацикливание, проходим циклицески 
    весь список снова и снова, думаю проблема в том что end и begin 
    указыват на друг на друга : end -> begin 
    */

    while (item != NULL)
    {
        if (item->size_block >= need_size)
        {
            return item;
        }
        item = item->next_inode;
    }
    return NULL;
}


struct inode*           
get_free_block(struct free_block_list* list)
{
    inode_t* item = list->begin;

    while (item != NULL)
    {
        if (item->is_free == _IS_FREE_BLOCK)
        {
            return item;
        }
        item = item->next_inode;
    }
    return NULL;
}



int                     
search_free_inode(struct inode* in, struct inode* answer)
{
    if (in->is_free == _IS_FREE_BLOCK)
    {
        answer = in;
        return 1;
    }
    else
        return -1;
}




void                    
for_each(struct free_block_list* list, inode_t* answer, funct_t f)
{
    inode_t* item   =  list->begin;

    while (item != NULL)
    {
        if (f(item, answer) >= 0)
            break;

        item = item->next_inode;
    }
}




int                     
is_empty(struct free_block_list* list)
{
    if (list->size == 0)
        return 1;
    else
        return -1;
}


void    
add_inode_to_free_list(struct free_block_list* list,
                        struct inode* p_inode)
{
    if (list->begin == NULL)
    {
        /* если список сейчас пуст */
        list->begin = p_inode;
        list->end   = p_inode;
    }
    else
    {
        list->end->next_inode = p_inode;
        list->end = p_inode;
    }   
    list->size++;
}


struct inode*    
remove_inode_from_free_list(struct inode* p_inode)
{
    if (p_inode->next_inode != NULL)
    {
        /* если это последная inode`а в списке */
        return pop_back(p_inode);
    }
    else
    {
        inode_t* tmp        = p_inode;
        p_inode->prev_inode = tmp->next_inode;
        tmp->is_free        = _IS_NOT_FREE_BLOCK;

        return tmp;
    }
}


struct inode*           
pop_back(struct inode* p_inode)
{
    inode_t* tmp                    = p_inode;
    p_inode->prev_inode->next_inode = NULL;
    tmp->is_free                    = _IS_NOT_FREE_BLOCK;

    return tmp;
}



struct inode*           
pop_front(struct free_block_list* list )
{
    inode_t* beg    = list->begin;
    inode_t* tmp    = beg->next_inode;
    
    list->begin     = tmp;
    tmp->prev_inode = NULL;

    return beg;
}





struct free_block_list* 
make_free_list()
{
    free_list_t* new_free_list = (free_list_t*)malloc(SIZE_FREE_LIST_STRUCT);
    
    new_free_list->begin    = NULL;
    new_free_list->end      = NULL;
    new_free_list->size     = 0;
    
    return new_free_list;
}


struct inode*           
make_inode(size_t size_inode)
{
    inode_t* new_inode = (inode_t*)malloc(size_inode);

    new_inode->is_free      = _IS_FREE_BLOCK;
    new_inode->next_inode   = NULL;
    new_inode->prev_inode   = NULL;
    new_inode->size_block   = 0;

    return new_inode;
}




void                    
delete_free_list(struct free_block_list* list)
{
    struct inode* item = list->begin;
    inode_t* tmp = NULL;

    while (item != NULL)
    {
        tmp = item;
        item = item->next_inode;
        free(tmp);
    }

    free(list);
}



int                     
test_print_block(struct inode* in)
{
    printf("[ size_block = %-5d\t\tis_free_flage = %d ]\n", 
            in->size_block, in->is_free);
    return 1;
}


void                    
test_print_free_list_struct(free_list_t* list)
{
    inode_t* item =  list->begin;

    while (item != NULL)
    {
        printf("item->size = %d\n", item->size_block);
        item = item->next_inode;
    }
    printf("\n");
}


void                    
test_print_free_blocks_to_free_list(struct free_block_list* list)
{
    inode_t* item = list->begin;

    while (item != NULL)
    {
        test_print_block(item);
        item = item->next_inode;
    }
}


void                    
print_count_reused_and_new_alloc()
{
    printf("count_new_allocation    = %d\n", count_new_alloc);
    printf("count_resude            = %d\n", count_reused);
}