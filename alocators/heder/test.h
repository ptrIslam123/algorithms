#ifndef _ALOCATORS_TEST_H_
#define _ALOCATORS_TEST_H_

#include "free_block_list.h"

#define _LOG_FILE_PATH_ "../log/log.txt"

void test1();
void test2();
void test3();
void test4();

void write_log(const char* );
void readf(const char* file, const char* mes);

#endif // !_ALOCATORS_TEST_H_