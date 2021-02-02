#include <stdio.h>

#include "graph.h"
#include "util.h"
#include "test.h"



int main()
{
    graph_t* g = make_graph(4);

    int v0[] = {1, 2};
    int v1[] = {0, 3};
    int v2[] = {0, 3};
    int v3[] = {1, 2};
    
    const int v0_size = sizeof(v0)/sizeof(v0[0]);
    const int v1_size = sizeof(v1)/sizeof(v1[0]);
    const int v2_size = sizeof(v2)/sizeof(v2[0]);
    const int v3_size = sizeof(v3)/sizeof(v3[0]);

    add_adj_list(g, 0, v0, v0_size);
    add_adj_list(g, 1, v1, v1_size);
    add_adj_list(g, 2, v2, v2_size);
    add_adj_list(g, 3, v3, v3_size);
    

    print_graph(g);

    
    print_weight_graph(g);


    algorithm_dijkstra(g, 0);

    //print_visited(g);


    print_weight_graph(g);



    free_graph(g);

    return 0;
}

