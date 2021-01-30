#! /usr/bin/env python 
from util import *
from selectionSort import *

arr = gen_array(20)


def sortList(array):
	length = len(array)

	for item in range(length):
		minimum = item

		for i in range(item + 1, length):
			if array[i] < array[minimum]:
				minimum = i

		(array[item], array[minimum]) = (array[minimum], array[item])


arr = gen_array(10)

print (arr)
print (selectionSort(arr))