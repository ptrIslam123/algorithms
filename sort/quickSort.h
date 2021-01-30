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



int* cancat_array(int *l_arr, int *r_arr,  int l_size, int r_size);

struct part_array* make_part_array(int* , int* , int , int);

int get_partition(int *arr, int size);

part_t* splitArray(int *arr, int x, int size);

int* quickSort(int *arr, int size);


#endif // !_QUICK_SORT_H_
