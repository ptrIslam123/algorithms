#! /usr/bin/env python 
from util import *
from bubleSort import bubleSort
from selectionSort import selectionSort


def main():
    data = [-12, 34, 0, 343434, 4]

    print ("before :", data)
    sortData = selectionSort(data)
    print ("after  :", sortData)

    return checkSort(sortData)


if __name__ == "__main__":
    main()