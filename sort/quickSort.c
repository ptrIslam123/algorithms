#include <stdlib.h>

#include "util.h"
#include "quickSort.h"
#include "selectionSort.h"

#define MIN_SIZE 5  // for example


array_and_size_t* quickSort(int* arr ,int size)
{
    if (size <= MIN_SIZE)
    {
        selectionSort(arr, size);
        return make_array_and_size_struct(arr, size);   
    }

    int x       = get_partition(arr, size);
    part_t* p   = splitArray(arr, x, size);

    array_and_size_t* l_sort_part_arr = quickSort(p->l_arr, p->l_size);
    array_and_size_t* r_sort_part_arr = quickSort(p->r_arr, p->r_size);
    
    int new_array_size = (l_sort_part_arr->size + 
                                r_sort_part_arr->size);
                                
     int *new_sort_array = mergeSort(
            l_sort_part_arr->arr,
            r_sort_part_arr->arr,
            l_sort_part_arr->size,
            r_sort_part_arr->size
    );

    return make_array_and_size_struct(
        new_sort_array,
        new_array_size
    );
}





array_and_size_t* make_array_and_size_struct(int *arr, int size)
{
    array_and_size_t* new_struct = (array_and_size_t*)malloc(sizeof(array_and_size_t));

    new_struct->arr = arr;
    new_struct->size = size;

    return new_struct;
}

struct part_array* make_part_array( int* l_arr, int* r_arr, 
                                    int l_size, int r_size  )
{
    const int size_part_arr = sizeof(part_t);
    
    part_t* new_part_arr = (part_t*)malloc(size_part_arr);
    
    int* new_l_arr = (int*)malloc(l_size);
    int* new_r_arr = (int*)malloc(r_size);

    new_part_arr->l_arr = new_l_arr;
    new_part_arr->r_arr = new_r_arr;

    new_part_arr->l_size = l_size;
    new_part_arr->r_size = r_size;

    return new_part_arr;
}

int get_partition(int *arr, int size)
{
    return arr[0];  // for example! 
}

int* mergeSort(int *l_arr, int *r_arr,  int l_size, int r_size)
{
    return NULL;
}

part_t* splitArray(int *arr, int x, int size)
{
    int *new_l_arr = (int*)malloc(sizeof(int) * size);
    int *new_r_arr = (int*)malloc(sizeof(int) * size);

    int r_size = 0, l_size = 0;
    int cur_val = 0;


    for (int i = 0; i < size; ++i)
    {
        cur_val = arr[i];

        if (cur_val < x)
        {
            new_l_arr[l_size++] = cur_val;
        }
        else
        {
            new_r_arr[r_size++] = cur_val;
        }   
    }

    return make_part_array(
        new_l_arr,
        new_r_arr,
        l_size,
        r_size
    );
}
