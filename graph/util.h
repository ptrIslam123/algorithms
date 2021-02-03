#ifndef _GRAPH_UTIL_H_
#define _GRAPH_UTIL_H_

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int             min(int , int );
void            add_node_to_adj_list(node_t *, node_t * );
graph_t*        make_graph(int );
node_t*         make_node(int );


void            set_matrix_adj_list(adj_matrix_t* , int , int * );
adj_matrix_t*   make_adj_matrix(int );


#endif // !_GRAPH_UTIL_H_
