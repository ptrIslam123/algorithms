#include <stdio.h>

#include "graph.h"
#include "util.h"
#include "test.h"


void test1();
void test2();

int main()
{
    
    adj_matrix_t *m = make_adj_matrix(4);

    int v0[] = {0, 2, 1, 0};
    int v1[] = {2, 0, 0, 5};
    int v2[] = {1, 0, 0, 4};
    int v3[] = {0, 5, 4, 0};

    int *v[] = {v0, v1, v2, v3};

    set_val_adj_matrix(m, v);

    print_adj_matrix(m);
    
    print_weight_graph(m);
    eval_weight_graph(m, 0, 0);
    print_weight_graph(m);

    /*
    set_matrix_adj_list(m, 0, v0);
    set_matrix_adj_list(m, 1, v1);
    set_matrix_adj_list(m, 2, v2);
    set_matrix_adj_list(m, 3, v3);
    */
    
    //print_adj_matrix(m);

    free_adj_matrix(m);

    return 0;
}


void test2()
{}

void test1()
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
}