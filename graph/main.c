#include <stdio.h>

#include "graph.h"
#include "util.h"

int main()
{
    graph_t* g = make_graph(4);

    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);

    add_edge(g, 2, 1);
    add_edge(g, 2, 4);

    add_edge(g, 3, 1);
    add_edge(g, 3, 4);

    add_edge(g, 4, 1);
    add_edge(g, 4, 2);
    add_edge(g, 4, 3);

    //print_graph(g);

    return 0;
}
