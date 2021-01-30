#include <stdio.h>
#include "util.h"

int* gen_array(int size)
{
    int *arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}

int minVal(int l, int r)
{
    if (l < r)
        return l;
    return r;
}

int getIndxMinVal(int *arr, int beg, int end)
{
    int minVal = arr[beg], minIndxVal = beg;

    for (int i = beg + 1; i < end; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            minIndxVal = i;
        }
    } 
    return minIndxVal;
}

int checkSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("[DEBUG] this is not sort array\n");
            return -1;
        }
    }
    return 0;
}

void swap(int* arr, int r, int l)
{
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void print(int* arr, int size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
        printf(" %d ", arr[i]);
    printf("]\n");
}