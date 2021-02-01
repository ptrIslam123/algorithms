#include <stdio.h>

#include "graph.h"
#include "util.h"
#include "test.h"

int main()
{
    graph_t* g = make_graph(4);
    
   /*
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
   */

    int v0[] = {1, 2, 3};
    int v1[] = {0, 2};
    int v2[] = {0, 1, 3};
    int v3[] = {0, 2};
    
    const int v0_size = sizeof(v0)/sizeof(v0[0]);
    const int v1_size = sizeof(v1)/sizeof(v1[0]);
    const int v2_size = sizeof(v2)/sizeof(v2[0]);
    const int v3_size = sizeof(v3)/sizeof(v3[0]);

    add_adj_list(g, 0, v0, v0_size);
    add_adj_list(g, 1, v1, v1_size);
    add_adj_list(g, 2, v2, v2_size);
    add_adj_list(g, 3, v3, v3_size);
   

    print_graph(g);
    
    

    dfs(g, 0);

    test_dfs(g);
    print_visited(g);


    set_visited_val(g, _IS_NOT_VISIED_);



    bfs(g, 3);

    test_bfs(g);
    print_visited(g);



    free_graph(g);

    return 0;
}
