#! /usr/bin/env python 
from util import *
from selectionSort import selectionSort

MIN_SIZE = 5

def mergerSort(l_arr, r_arr):
    new_arr = []
    min_arr = []; max_element = 0

    for i in range(len(l_arr)):

        j = i
        while min_arr[j] < max_element:
            new_arr[j] = min_arr[j]
            j += 1

        new_arr[j] = max_element

    return new_arr

def split_array(arr, x):
    l_arr = []; r_arr = []

    for i in range(len(arr)):
        if arr[i] < x:
            l_arr.append(arr[i])
        else:
            r_arr.append(arr[i])

    return l_arr, r_arr


def get_partition(arr):
    return arr[0]


def quickSort(arr):
    size = len(arr)

    if MIN_SIZE <= size:
        return selectionSort(arr)

    x               = get_partition(arr)
    l_arr, r_arr    = split_array(arr, x)

    l_sort_arr = quickSort(l_arr)
    r_sort_arr = quickSort(r_arr)

    return mergerSort(l_sort_arr, r_sort_arr)