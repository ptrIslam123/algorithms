#include <stdio.h>

#include "graph.h"
#include "util.h"



void dfs(graph_t *p_graph, int vertex)
{
    const int count_v = p_graph->count_vertex;
    node_t *cur_vert = NULL;

    for (int i = 0; i < count_v; ++i)
    {
        cur_vert = p_graph->adj_list[i];

        if (p_graph->visited[cur_vert->num_vertex] == _IS_NOT_VISIED_)
        {
            p_graph->visited[cur_vert->num_vertex] = _VISITED_;
            dfs(p_graph ,cur_vert->num_vertex);
        }
    }
}

void bfs(graph_t* p_graph, int vertex)
{
    node_t *cur_vert = p_graph->adj_list[vertex];

    p_graph->visited[cur_vert->num_vertex] = _VISITED_;


    while (cur_vert != NULL)
    {
        if (p_graph->visited[cur_vert->num_vertex] == _IS_NOT_VISIED_)
        {
            bfs(p_graph, cur_vert->num_vertex);
        }

        cur_vert = cur_vert->next_node;
    }
}

void add_adj_list(graph_t* p_graph, int vertex, int* adj_list, int size)
{
    for (int i = 0; i < size; ++i)
    {
        add_edge(p_graph, vertex, adj_list[i]);
    }
}

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
    return NULL;
}



void set_visited_val(graph_t *p_graph, int val)
{
    for (int i = 0; i < p_graph->count_vertex; ++i)
    {
        p_graph->visited[i] = val;
    }
}


void print_visited(graph_t *p_graph)
{
    for (int i = 0; i < p_graph->count_vertex; ++i)
        printf("vertex[%d] -> %d\n", i, p_graph->visited[i]);

    printf("\n");
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
    printf("\n");
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
    return p_graph->adj_list[vertex]; 
}



void free_graph(graph_t* p_graph)
{
    const int count_v = p_graph->count_vertex;

    for (int i = 0; i < count_v; ++i)
    {
        free_adj_list(p_graph->adj_list[i]);
    }

    free(p_graph->adj_list);
    free(p_graph);

    p_graph = NULL;
}


void free_adj_list(node_t* p_ajd_lsit)
{
    node_t *tmp = NULL;

    while (p_ajd_lsit != NULL)
    {
        tmp = p_ajd_lsit;
        p_ajd_lsit = p_ajd_lsit->next_node;

        free(tmp);
    }
}