#! /usr/bin/env python 

def getIndxMinVal(arr, beg, end):
    minIndx = 0; minVal = 0
    
    if beg >= end:
        return -1
    minVal = arr[beg]

    for i in range(beg + 1, end):
        if arr[i] < minVal:
            minVal  = arr[i]
            minIndx = i

    return minIndx

def checkSort(arr):
    i = 0
    while i < len(arr) - 1:
        if (arr[i] > arr[i + 1]):
            raise RuntimeError("[DEBUG] this is not sort array ")
        i += 1



def swap(arr, r, l):
    tmp = arr[l]
    arr[l] = arr[r]
    arr[r] = tmp
