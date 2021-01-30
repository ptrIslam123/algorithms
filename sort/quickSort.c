#include <stdlib.h>

#include "util.h"
#include "quickSort.h"
#include "selectionSort.h"

#define MIN_SIZE 5  // for example


int* quickSort(int* arr ,int size)
{
    if (size <= 1)
        return arr;

    int x = get_partition(arr, size);
    part_t* res = splitArray(arr, x , size);

    int* l_sort_arr = quickSort(res->l_arr, res->l_size);
    int* r_sort_arr = quickSort(res->r_arr, res->r_size);

    return cancat_array(l_sort_arr, r_sort_arr, 
                        res->l_size, res->r_size);
}



int* cancat_array(int *l_arr, int *r_arr,  int l_size, int r_size)
{
    int *new_arr = (int*)malloc(sizeof(int) * l_size + r_size);
    int i;
    

    for (i = 0; i < l_size; ++i)
    {
        new_arr[i] = l_arr[i];
    }

    for (; i < r_size; ++i)
    {
        new_arr[i] = r_arr[i];
    }

    return new_arr;
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
    return arr[0];
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
