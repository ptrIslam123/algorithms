#include "util.h"

#define SIZE_NODE       (sizeof(struct node))
#define SIZE_NODE_PTR   (sizeof(struct node*))
#define SIZE_GRAPH      (sizeof(struct graph))


void add_node_to_adj_list(node_t *vertex, node_t *new_node)
{
    while (vertex->next_node != NULL)
    {
        vertex = vertex->next_node;
    }

    vertex->next_node = new_node;
}


graph_t* make_graph(int count_vert)
{
    struct graph *new_graph = (graph_t*)malloc(SIZE_GRAPH);

    new_graph->count_vertex = count_vert;
    new_graph->visited      = (int*)malloc(sizeof(int) * count_vert);
    new_graph->adj_list     = (node_t**)malloc(SIZE_NODE_PTR * count_vert);

    for (int i = 0; i < count_vert; ++i)
    {
        new_graph->adj_list[i]  = NULL;
        new_graph->visited[i]   = 0;
    }    

    return new_graph;
}

node_t* make_node(int vert)
{
    struct node *new_node   = (node_t*)malloc(SIZE_NODE);

    new_node->num_vertex    = vert;
    new_node->next_node     = NULL;

    return new_node;
}
