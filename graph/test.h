#ifndef _GRAPH_TEST_H_
#define _GRAPH_TEST_H_

#include "graph.h"
#include "util.h"

void test3();
void test1();
void test2();

void test_weight_adj_matrix(adj_matrix_t* , int* );
void test_visited(int* , int );
void compare_arrays(int *, int* , int);
void test_bfs(graph_t* );
void test_dfs(graph_t* );

#endif // !_GRAPH_TEST_H_
