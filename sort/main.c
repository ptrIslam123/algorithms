#include <stdio.h>

#include "util.h"
#include "bubleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "quickSort.h"


int main()
{
    int *arr = NULL;
    /*
     for (int i = 0; i < 10; ++i)
    {
        int size = i + 9;
        arr = gen_array(size);
        print(arr, size);


        quickSort(arr, size);
        print(arr, size);
        checkSort(arr, size);
    }
     */
    arr = gen_array(10);
    print(arr, 10);

    quickSort(arr, 10);

    print(arr, 10);

    return 0;
}