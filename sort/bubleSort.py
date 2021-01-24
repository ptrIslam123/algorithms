#! /usr/bin/env python 
from util import *


data = [1,23,343,4345,5656,7]





'''
void bubleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}
'''

def bubleSort(arr):
    size = len(arr)

    for i in range(size - 1):
        for j in range(0, size - 1 - i):
            if arr[j] > arr[j + 1]:
                swap(arr, j, j + 1)
    return arr




def main():
    print (data)

    sortData = bubleSort(data)
    
    print(sortData)
    

    return checkSort(sortData)

if __name__ == "__main__":
    main()