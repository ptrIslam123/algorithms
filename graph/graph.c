#include <stdio.h>

#include "graph.h"
#include "util.h"

node_t* add_edge(graph_t* p_graph, int vert, int new_adj_vert)
{   
    if (p_graph->adj_list[vert] == NULL)
    {
        p_graph->adj_list[vert] = make_node(vert);
    }

    node_t *new_node = make_node(new_adj_vert);
    add_node_to_adj_list(p_graph->adj_list[vert], new_node);

    return new_node;
}


node_t* remove_edge(graph_t* p_graph, int src, int dest)
{

}


void print_graph(graph_t* p_graph)
{ 
    const int count_v = p_graph->count_vertex;

    for (int i = 0; i < count_v; ++i)
    {
        if (p_graph->adj_list[i] == NULL)
            break;

        printf(" %d -> ", p_graph->adj_list[i]->num_vertex);
        print_adj_list(p_graph->adj_list[i]->next_node);
    }
}


void print_adj_list(node_t* vertex)
{
    printf("{ ");
    while (vertex->next_node != NULL)
    {
        printf("  %d  ", vertex->num_vertex);
        vertex = vertex->next_node;
    }
    printf("%d  }\n", vertex->num_vertex);
}

node_t* find_edge(graph_t* p_graph, int vertex)
{

}

void    free_graph(graph_t* p_graph)
{

}