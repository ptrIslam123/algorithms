#include "util.h"

#define SIZE_NODE       (sizeof(struct node))
#define SIZE_NODE_PTR   (sizeof(struct node*))
#define SIZE_GRAPH      (sizeof(struct graph))


void add_node_to_adj_list(node_t *vertex, node_t *add_vertex)
{
    while (!vertex->next_node)
    {
        vertex = vertex->next_node;
    }

    vertex->next_node = add_vertex;
}


graph_t* make_graph(int count_vert)
{
    struct graph* new_graph = (graph_t*)malloc(SIZE_GRAPH);

    new_graph->adj_list = (node_t**)malloc(SIZE_NODE_PTR * count_vert);
    new_graph->visited  = (int*)malloc(sizeof(int) * count_vert);

    for (int i = 0; i < count_vert; ++i)
    {
        new_graph->adj_list[i]  = NULL;
        new_graph->visited[i]   = _IS_NOT_VISIED_;
    }

    return new_graph;
}

node_t* make_node(int vert)
{
    struct node* new_node = (node_t*)malloc(SIZE_NODE);

    new_node->next_node = NULL;
    new_node->vertex = vert;

    return new_node;
}