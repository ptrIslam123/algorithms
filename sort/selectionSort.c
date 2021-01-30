#include "util.h"



void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        int minIndx = getIndxMinVal(arr, i , size);
        swap(arr, i, minIndx);
    }
}

