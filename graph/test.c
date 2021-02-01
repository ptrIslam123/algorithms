#include <stdio.h>
#include <stdlib.h>

#include "test.h"



void test_visited(graph_t* p_graph)
{
    for (int i = 0; i < p_graph->count_vertex; ++i)
    {
        if (p_graph->visited[i] == _IS_NOT_VISIED_)
        {
            printf("[DEBUG] Error function -> test_visited");
            exit(-1);
        }
    }
}

void test_bfs(graph_t* p_graph)
{
    test_visited(p_graph);
}

void test_dfs(graph_t* p_graph)
{
    test_visited(p_graph);
}