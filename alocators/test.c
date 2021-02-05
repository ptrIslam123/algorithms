#include "heder/test.h"


void test_delete_free_list()
{
    test_remove();
    delete_free_list(get_free_list_struct()); // error
}

void test_remove()
{
    int size = 100;
    int** arr = test_allocate(size);

    for (int i = 0; i < size; ++i)
    {
        deallocate(arr[i]);
    }

    deallocate(arr);
}

int** test_allocate(int size_array)
{
    int size = 0;
    int** array_ptr = allocate(sizeof(int*) * size_array);
    for (int i = 0; i < size_array; ++i)
    {
        size = (rand() % 99) + 1;
        int *arr = allocate(sizeof(int) * size);

        init_array(arr, size);

        printf("\t\tarray size = %d\n", size);
        //print_array("arr", arr, size);

        array_ptr[i] = arr;
    }
    return array_ptr;
}




void test_pop_front()
{
    int size = 3;
    int **arr = allocate(sizeof(int*) * size);

    for (int i = 0; i < size; ++i)
    {
        int s = (rand() % 29) + 1;
        arr[i] = allocate(sizeof(int) * s);

        printf("allocate size = %d\n", sizeof(int) * s);
        init_array(arr[i], s);
    }

    printf("allocating\n\n");




    for (int i = 0 ; i < size; ++i)
    {
        printf("deallocate => ");
        test_print_block(get_inode(arr[i]));
        deallocate(arr[i]);
    }

    printf("deallocationg free list struct\n\n");



    free_list_t* list = get_free_list_struct();

    while (list->size != 0)
    {
        inode_t* in = pop_front(list);
        printf("pop_front inode => ");
        test_print_block(in);
    }
    printf("delete free list struct(pop_front)\n\n");

    test_print_free_blocks_to_free_list(get_free_list_struct());
    printf("print free list struct\n\n");

    delete_free_list(get_free_list_struct());
    printf("delete struct\n\n");
}


void test7()
{
    int size = 3;
    int **arr = allocate(sizeof(int*) * size);

    for (int i = 0; i < size; ++i)
    {
        int s = (rand() % 29) + 1;
        arr[i] = allocate(sizeof(int) * s);

        printf("allocate size = %d\n", sizeof(int) * s);
        init_array(arr[i], s);
    }

    printf("allocating\n\n");

    for (int i = 0 ; i < size; ++i)
    {
        printf("deallocate => ");
        test_print_block(get_inode(arr[i]));
        deallocate(arr[i]);
    }

    printf("deallocationg free list struct\n\n");

    delete_free_list(get_free_list_struct());
    printf("delete fre list struct\n\n");
}

void test6()
{
    int size = 3;
    int **arr = allocate(sizeof(int*) * size);

    for (int i = 0; i < size; ++i)
    {
        int s = (rand() % 29) + 1;
        arr[i] = allocate(sizeof(int) * s);

        printf("allocate size = %d\n", sizeof(int) * s);
        init_array(arr[i], s);
    }

    printf("allocating\n\n");

    
    for (int i = 0; i < size; ++i)
    {
        inode_t* in = get_inode(arr[i]);

        add_inode_to_free_list(get_free_list_struct() ,in);
    }

    test_print_free_blocks_to_free_list(get_free_list_struct());

    printf("append inodes to free list struct\n\n");


    for (int i = size - 1; i >= 0; --i)
    {
        inode_t* in = get_inode(arr[i]);

        printf("removing inode => {size = %d}\n", in->size_block);
        remove_inode_from_free_list(in);
    }

    printf("removing inodes\n\n");
}


void test5()
{
    int size = 1000;
    int **arr = allocate(sizeof(int*) * size);

    for (int i = 0; i < size; ++i)
    {
        int s = (rand() % 29) + 1;
        arr[i] = allocate(sizeof(int) * s);

        printf("allocate size = %d\t\t||", sizeof(int) * s);
        init_array(arr[i], s);

        printf("deallocate => ");
        test_print_block(get_inode(arr[i]));
        deallocate(arr[i]);
    }

    printf("allocating\n\n");

    print_count_reused_and_new_alloc();

    delete_free_list(get_free_list_struct());
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




    delete_free_list(get_free_list_struct());
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
    

    test_print_free_blocks_to_free_list(list);
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


void init_array(int* arr, int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        arr[i] = rand() % 10000;
    }
}

void print_array(const char* str, int* arr, int size)
{
    for (int i = 0 ; i < size; ++i)
    {
        printf("%s[%d] = %d\n" , str, i, arr[i]);
    }
    printf("\n");
}
