#! /usr/bin/env python 
from util import *
from selectionSort import selectionSort
import random as random

MIN_SIZE = 5


def get_partition(arr):
    n = len(arr) 
    return arr[random.randint(0, n - 1)]


def split_array(arr, x):
    l_arr = []; r_arr = []

    for i in range(len(arr)):
        if arr[i] < x:
            l_arr.append(arr[i])
        else:
            r_arr.append(arr[i])

    return l_arr, r_arr


def quickSort(arr):
    size = len(arr)

    if size <= MIN_SIZE:
        return selectionSort(arr)

    x               = get_partition(arr)
    l_arr, r_arr    = split_array(arr, x)

    l_sort_arr = quickSort(l_arr)
    r_sort_arr = quickSort(r_arr)

    return l_sort_arr + r_sort_arr