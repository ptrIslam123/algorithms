#include "heder/test.h"


void print_array(const char* str, int* arr, int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        printf("%s[%d] = %d\n" , str, i, arr[i]);
    }
    printf("\n");
}

void test4()
{
    const int size = 10;
    int* x = allocate(sizeof(int) * size);
    int* y = allocate(sizeof(int) * size);
    
    for (int i = 0; i < size; ++i)
    {
        x[i] = i + i*i;
    }


    for (int i = 0; i < size; ++i)
    {
        y[i] = i + (i + 1);
    }

    print_array("x", x, size);
    print_array("y", y, size);

    deallocate(x);
    deallocate(y);
}

void test3()
{
    inode_t* in = make_inode(SIZE_INODE_STRUCT + sizeof(int));

    test_print_block(in);

    int* m_data = (int*)( (void*)in + SIZE_INODE_STRUCT );
    *m_data = 10;

    printf("member data in struct inode in (m_data -> )= %d\n",
        *(int*)( (void*)in + SIZE_INODE_STRUCT ));


    test_print_block(in);
}

void test2()
{
    const int size = 10;
    free_list_t* list = get_free_list_struct();

    for (int i = 0; i < size; ++i)
    {
        inode_t* in = make_inode(SIZE_INODE_STRUCT);
        in->size_block = i + (100*i + 100);

        add_inode_to_free_list(list, in);
    }


    test_print_free_blocks_to_free_list(list);

   
    printf("get_free_block:\n");
    test_print_block(get_free_block(list));

    //test_print_free_blocks_to_free_list(list);
}


void test1()
{
    const int size = 10;
    free_list_t* list = get_free_list_struct();

    for (int i = 0; i < size; ++i)
    {
        inode_t* in = make_inode(SIZE_INODE_STRUCT);
        in->size_block = i + 10;

        add_inode_to_free_list(list, in);
    }

    test_print_free_list_struct(list);
}




void write_log(const char* data)
{
    readf(_LOG_FILE_PATH_, data);
}


void readf(const char* file, const char* mes)
{
    FILE* fd = fopen(file, "a");
    if (fd != NULL)
    {
        fputs(mes, fd);
        fclose(fd);
    }
    else
    {
        exit(-1);   
    }
}

