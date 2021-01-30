#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "util.h"

typedef struct part_array
{
    int* l_arr;
    int* r_arr;
    int l_size;
    int r_size;
} part_t;


typedef struct array_and_size
{
    int* arr;
    int size;
} array_and_size_t;


int* mergeSort(int *l_arr, int *r_arr,  int l_size, int r_size);

array_and_size_t* get_min_array_and_max_element(int* , int* , int );

array_and_size_t* make_array_and_size_struct(int *arr, int size);

struct part_array* make_part_array(int* , int* , int , int);

int get_partition(int *arr, int size);

part_t* splitArray(int *arr, int x, int size);

array_and_size_t* quickSort(int *arr, int size);


#endif // !_QUICK_SORT_H_
