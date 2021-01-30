#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdlib.h>

int* gen_array(int size);

int min(int , int);

int minVal(int l, int r);

int getIndxMinVal(int *arr, int beg, int end);

int checkSort(int *arr, int size);

void swap(int* arr, int r, int l);

void print(int* arr, int size);


#endif // !_UTIL_H_