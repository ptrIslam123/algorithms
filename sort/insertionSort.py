#! /usr/bin/env python 
from util import *


def reverseSort(arr, size):
    i = size

    while (i >= 0):
        if arr[i] > arr[i + 1]:
            swap(arr, i ,i + 1)
        i -= 1

def insertionSort(arr):
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            reverseSort(arr, i)
    
    return arr