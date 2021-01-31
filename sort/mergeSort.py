#! /usr/bin/env python 
from util import *


def merge_array(a, b):
    size_a = len(a); size_b = len(b)
    i = j = k = 0
    c = []

    while (i < size_a and j < size_b):
        if (a[i] < b[j]):
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1

    while (i < size_a):
        c.append(a[i])
        k += 1; i += 1

    while (j < size_b):
        c.append(b[j])
        j += 1

    return c


def split_array(arr):
	s = len(arr)
	n = int(s/2)
	m = s - n
	
	l_arr = []; r_arr = []

	for i in range(0, n):
		l_arr.append(arr[i])

	for j in range(n, s):
		r_arr.append(arr[j])

	return l_arr, r_arr



def mergeSort(arr):
    size = len(arr)

    if size <= 1:
        return arr

    l_arr, r_arr = split_array(arr)

    l_sort_arr = mergeSort(l_arr)
    r_sort_arr = mergeSort(r_arr)

    return merge_array(l_sort_arr, r_sort_arr)