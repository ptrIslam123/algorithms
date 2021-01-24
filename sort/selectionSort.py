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

    for i in range(size - 1):
        minIndx = getIndxMinVal(arr, i, size)
        swap(arr, i, minIndx)

    return arr

