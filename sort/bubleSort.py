#! /usr/bin/env python 


data = [1,23,343,4345,5656,7]


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