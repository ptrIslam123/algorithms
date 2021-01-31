#ifndef _GRAPH_UTIL_H_
#define _GRAPH_UTIL_H_

#include <stdlib.h>
#include "graph.h"

void        add_node_to_adj_list(node_t *, node_t * );

graph_t*    make_graph(int count_vert);

node_t*     make_node(int vert);

#endif // !_GRAPH_UTIL_H_
