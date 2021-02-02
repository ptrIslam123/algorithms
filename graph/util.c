#include <limits.h>
#include "util.h"

#define SIZE_NODE       (sizeof(struct node))
#define SIZE_NODE_PTR   (sizeof(struct node*))
#define SIZE_GRAPH      (sizeof(struct graph))
#define SIZE_ADJ_MATRIX (sizeof(struct adj_matrix))


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






void set_matrix_adj_list(adj_matrix_t *matrix, int vertex, int *adj_list)
{
    const int size = matrix->size;

    for (int i = 0; i < size; ++i)
    {
        matrix->m[vertex][i] = adj_list[i];
    }
}


adj_matrix_t* make_adj_matrix(int size)
{
    adj_matrix_t* new_adj_matrix = (adj_matrix_t*)malloc(SIZE_ADJ_MATRIX);

    new_adj_matrix->m       = (int**)malloc(sizeof(int*) * size);
    new_adj_matrix->visited = (int*)malloc(sizeof(int) * size);
    new_adj_matrix->weight  = (int*)malloc(sizeof(int) * size); 
    new_adj_matrix->size    = size;

    for (int i = 0; i < size; ++i)
    {
        new_adj_matrix->m[i]        = (int*)malloc(sizeof(int) * size);
        new_adj_matrix->visited[i]  = _IS_NOT_VISIED_;
        new_adj_matrix->weight[i]   = INT_MAX;

        for (int j = 0 ; j < size; ++j)
            new_adj_matrix->m[i][j] = 0;
    }

    return new_adj_matrix;
}