#include <stdio.h>

#include "graph.h"
#include "util.h"

void add_edge(graph_t* p_graph, int vert, int add_vert)
{
   node_t *new_vert_node = make_node(add_vert);

   node_t *vert_node = p_graph->adj_list[vert];

   if (!vert_node)
   {
       vert_node = make_node(vert);
   }

   add_node_to_adj_list(vert_node, new_vert_node);
}


void remove_edge(graph_t* p_graph, int src, int dest)
{

}


void    print_graph(graph_t* p_graph)
{
    const int vertex_count = p_graph->num_vertex;
    node_t *cur_vertex = NULL;

    for (int i = 0; i < vertex_count; ++i)
    {
        cur_vertex = p_graph->adj_list[i];

        printf("%d -> ", cur_vertex->vertex);
        print_adj_list(cur_vertex);
    }
}


void print_adj_list(node_t* vertex)
{
    printf("{ ");
    while (!vertex->next_node)
    {
        printf(" %d ", vertex->vertex);
        vertex = vertex->next_node;
    }
    printf(" }\n");
}

node_t* find_edge(graph_t* p_graph, int vertex)
{

}

void    free_graph(graph_t* p_graph)
{

}