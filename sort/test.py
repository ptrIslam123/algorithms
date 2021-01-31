#! /usr/bin/env python 
from util import *
from selectionSort import *
from mergeSort import *



def sortList(array):
	length = len(array)

	for item in range(length):
		minimum = item

		for i in range(item + 1, length):
			if array[i] < array[minimum]:
				minimum = i

		(array[item], array[minimum]) = (array[minimum], array[item])



def print_list(arr, beg, end):
	for i in range(beg, end):
		print (arr[i])
	
	print ("\n")


def split(arr):
	s = len(arr)
	n = int(s/2)
	m = s - n
	
	l_arr = []; r_arr = []

	for i in range(0, n):
		l_arr.append(arr[i])

	for j in range(n, s):
		r_arr.append(arr[j])

	return l_arr, r_arr


arr = selectionSort(gen_array(5))
print (arr)

l_arr, r_arr = split(arr)

print (l_arr)
print (r_arr)


