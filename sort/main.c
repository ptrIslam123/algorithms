#include <stdio.h>

#include "util.h"
#include "bubleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"


int main()
{

    int data[]          = {12,-34, 0, 343434, 3, 4545};
    const size_t size   = sizeof(data)/sizeof(data[0]);


    printf("before sort:\t");
    print(data, size);

    insertionSort(data, size);

    printf("after sort:\t");
    print(data, size);


    return checkSort(data, size);
}