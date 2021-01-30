#! /usr/bin/env python
import random as r 

def gen_array(size):
    arr = []

    for i in range(size):
        arr.append(
            r.randint(1, 1000)
        )
    return arr



def getIndxMinVal(arr, beg, end):
    minVal = arr[beg]; minIndxVal = beg
    
    for i in range(beg + 1, end):
        if arr[i] < minVal:
            minVal = arr[i]
            minIndxVal = i
       
    return minIndxVal



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
