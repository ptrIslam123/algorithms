#include "heder/free_block_list.h"


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




#define is_not_empty(list) (is_empty(list) >= 0)

struct inode*           
alloc_inode(size_t total_size)
{
    free_list_t* list = get_free_list_struct();
    inode_t* result = NULL;

    if (is_not_empty(list))
    {
        /* если наш список не пуст */
        result = get_suitable_free_block(list, total_size);

        /* если среди свобожный блоков нашелся подходящий блок */
        if (result != NULL)
            return result;
        else
        {
            /* если не смогли найти подходящий свободный блок,
                то выделяем в heap`е новый блок памяти */
            return make_inode(total_size);
        }
    }
    else
    {
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



struct inode*           
get_suitable_free_block(struct free_block_list* list, size_t need_size)
{
    inode_t* item = list->begin;
    
    while (item != NULL)
    {
        if (item->is_free == _IS_FREE_BLOCK &&
            item->size_block >= need_size)
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
pop_front()
{
    free_list_t* list = get_free_list_struct();
    
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