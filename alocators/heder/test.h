#ifndef _ALOCATORS_TEST_H_
#define _ALOCATORS_TEST_H_

#include "free_block_list.h"

#define _LOG_FILE_PATH_ "../log/log.txt"

void test_delete_free_list();
int** test_allocate(int );
void test_remove();


void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test_pop_front();


void init_array(int* arr, int size);

void print_array(const char* str, int* arr, int size);

void write_log(const char* );
void readf(const char* file, const char* mes);

#endif // !_ALOCATORS_TEST_H_