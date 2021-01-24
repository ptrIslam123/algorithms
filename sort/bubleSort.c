#include <stdio.h>
#include <stdlib.h>

int data[] = {123,-12,3, 34,4,34343,55};


int checkSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("[DEBUG] this is not sort array\n");
            return -1;
        }
    }
    return 0;
}

void swap(int* arr, int r, int l)
{
    int tmp = arr[l];
    arr[l] = arr[r];
    arr[r] = tmp;
}

void print(int* arr, int size)
{
    printf("[");
    for (int i = 0; i < size; ++i)
        printf(" %d ", arr[i]);
    printf("]\n");
}

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

int main()
{
    const size_t size = sizeof(data)/sizeof(data[0]);
    print(data, size);

    bubleSort(data, size);

    print(data, size);

    
    return checkSort(data, size);
}