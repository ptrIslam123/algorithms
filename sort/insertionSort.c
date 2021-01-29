#include "util.h"
#include "insertionSort.h"


void insertionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            reverseSort(arr, i);
    }
}


void reverseSort(int* arr, int size)
{
    for (int i = size; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
            swap(arr, i, i + 1);
    }
}