#ifndef _ALOCATORS_FREE_BLOCK_LIST_H_
#define _ALOCATORS_FREE_BLOCK_LIST_H_

#include <stdlib.h>
#include <stdio.h>

#define SIZE_FREE_LIST_STRUCT   (sizeof(struct free_block_list))
#define SIZE_INODE_STRUCT       (sizeof(struct inode))

#define _IS_FREE_BLOCK          (1)
#define _IS_NOT_FREE_BLOCK      (0)

struct free_block_list;
struct inode;


typedef int (*funct_t)(struct inode* , struct inode* );

typedef struct free_block_list
{
    size_t          size;
    struct inode*   begin;
    struct inode*   end;
} free_list_t;


typedef struct inode
{
    unsigned char   is_free;
    size_t          size_block;
    struct inode*   next_inode;
    struct inode*   prev_inode;
} inode_t;


void*   allocate(size_t );
void    deallocate(void* );



struct inode*           alloc_inode(size_t );


struct free_block_list* get_free_list_struct();


struct inode*           get_suitable_free_block(struct free_block_list* , size_t );
struct inode*           get_free_block(struct free_block_list* );
int                     search_free_inode(struct inode* , struct inode* ); 

void                    for_each(struct free_block_list* , inode_t* , funct_t );

int                     is_empty(struct free_block_list* );
void                    add_inode_to_free_list(struct free_block_list* , struct inode* );
struct inode*           remove_inode_from_free_list(struct inode* );
struct inode*           pop_back(struct inode* );
struct inode*           pop_front(struct free_block_list* );

struct free_block_list* make_free_list();
struct inode*           make_inode(size_t );

void                    delete_free_list(struct free_block_list* );

int                     test_print_block(struct inode* );
void                    test_print_free_list_struct(free_list_t* );
void                    test_print_free_blocks_to_free_list();
void                    print_count_reused_and_new_alloc();


#endif // !_ALOCATORS_FREE_BLOCK_LIST_H_
