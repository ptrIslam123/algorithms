#include <stdio.h>

#include "graph.h"
#include "util.h"

int main()
{
    graph_t* g = make_graph(4);
    
    
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 0, 3);

    add_edge(g, 1, 0);
    add_edge(g, 1, 2);

    add_edge(g, 2, 0);
    add_edge(g, 2, 1);
    add_edge(g, 2, 3);

    add_edge(g, 3, 0);
    add_edge(g, 3, 2);

   

    print_graph(g);
    return 0;
}
