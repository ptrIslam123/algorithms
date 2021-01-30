#! /usr/bin/env python 
from util import *
from bubleSort import bubleSort
from selectionSort import selectionSort
from insertionSort import insertionSort
from quickSort import *


def main():

    for i in range(10):
        
        arr = gen_array(i + 9)
        print ("iteration: ", i + 1)
        print ("before sort: ",arr)

        sort_data = quickSort(arr)

        print ("after sort:  ", sort_data)

        checkSort(sort_data)




    #return checkSort(sortData)


if __name__ == "__main__":
    main()

    