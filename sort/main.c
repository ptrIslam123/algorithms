#include <stdio.h>

#include "util.h"
#include "bubleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "quickSort.h"


int main()
{
    int *arr = NULL;
    for (int i = 0; i < 10; ++i)
    {
        int size = i + 9;
        arr = gen_array(size);
        print(arr, size);


        selectionSort(arr, size);
        print(arr, size);
        checkSort(arr, size);
    }

    return 0;
}