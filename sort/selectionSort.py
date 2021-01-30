#! /usr/bin/env python 
from util import *


'''
void selectionSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndx = getIndxMinVal(arr, i , size);
        swap(arr, i, minIndx);
    }
}
'''

def selectionSort(arr):
    size = len(arr)

    for item in range(size):
        minIndxVal = getIndxMinVal(arr, item, size)
        #(arr[item], arr[minIndxVal]) = (arr[minIndxVal], arr[item])
        swap(arr, item, minIndxVal)
    return arr

