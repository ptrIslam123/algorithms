#include <stdio.h>
#include <limits.h>

#include "graph.h"
#include "util.h"

#define TEST



#ifndef TEST

void foo(adj_matrix_t *p_graph, int vertex)
{
    p_graph->weight[vertex] = 0;
    int min_index = 0;
    int min = min_index;
    int temp = 0;int size = p_graph->size;

    do {

       min_index = INT_MAX;
       min = min_index;

       for (int i = 0; i < size; ++i)
       {
           if (p_graph->visited[i] == _IS_NOT_VISIED_ &&
                p_graph->weight[i] < min)
                {
                    min_index = i;
                    min = p_graph->weight[i];
                }
       } 


       if (min_index != INT_MAX)
       {
           for (int i = 0; i < size; ++i)
           {
               temp = min + p_graph->m[min_index][i];
               if (temp < p_graph->weight[i])
               {
                   p_graph->weight[i] = temp;
               }
           }
       }

       p_graph->visited[min_index] = _VISITED_;

    }while (min_index < INT_MAX);
}

#endif // !TEST

/* НЕОБХОДИМО ДОРАБОТАТЬ */
void algorithm_floyd(adj_matrix_t *p_graph , int vertex)
{
    const int size = p_graph->size;

    for (int k = 0; k < size; ++k)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                p_graph->m[i][j] = min(
                    p_graph->m[i][j], p_graph->m[i][k] + p_graph->m[k][j]
                );
            }
        }
    }
}



/* НЕОБХОДИМО ДОРАБОТАТЬ */
void algorithm_dijkstra(adj_matrix_t *p_graph, int vertex)
{
    p_graph->weight[vertex] = _VISITED_;
    eval_weight_graph(p_graph);
}


/*
    1.  получаем начальную вершину с которой начинаем. 
        Помечаем эту вершину как посещенную,
        а так же получаем список смежных с ней вершин.

    2.  В цикле рекурсивно проходимся по всем смежных вершинам
        которые еще не были посещены. В этом цикле высчитываем новые 
        весовые коэффиценты для каждой смежной вершины 
        по формуле (weight = weight + parent_weight)

*/
void eval_weight_graph(adj_matrix_t *p_graph)
{
    int min_index = 0;

   do{

        min_index = get_min(p_graph);

        if (min_index != INT_MAX)
        {
            update_weight_vertex(p_graph, min_index);
        }
        p_graph->visited[min_index] = _VISITED_;
   }while (min_index < INT_MAX);
}

int get_min(adj_matrix_t *p_graph)
{
    const int size  = p_graph->size;
    int min_index   = INT_MAX;
    int min_val     = min_index;

    for (int i = 0; i < size; ++i)
    {
        if (p_graph->visited[i] == _IS_NOT_VISIED_ && 
            p_graph->weight[i] < min_val)
            {
                min_val     = p_graph->weight[i];
                min_index   = i;
            }
    }
    return min_index;   
}


void update_weight_vertex(adj_matrix_t *p_graph, int min_index)
{
    int *vertex         = p_graph->m[min_index];
    int parent_weight   = p_graph->weight[min_index];
    const int size      = p_graph->size;
    int new_weight      = 0;

    for (int i = 0; i < size; ++i)
    {
        new_weight = parent_weight + vertex[i];

        if (new_weight < p_graph->weight[i])
        {
            p_graph->weight[i] = new_weight;
        }
    }
}



void print_visited_adj_matrix(adj_matrix_t *p_grpah)
{
    const int size = p_grpah->size;

    for (int i = 0; i < size; ++i)
    {
        printf("visited[%d] -> %d\n",i, p_grpah->visited[i]);
    }
    printf("\n");
}



void print_weight_adj_matrix(adj_matrix_t* p_graph)
{
    const int size = p_graph->size;
    for (int i = 0; i < size; ++i)
    {
        if (p_graph->weight[i] == INT_MAX)
            printf("vertex_weight[%d] -> INF\n", i);
        else
            printf("vertex_weight[%d] -> %d\n", i, p_graph->weight[i]);
    }
    printf("\n");
}


void print_weight_graph(graph_t *p_graph)
{
    const int size  = p_graph->count_vertex;
    node_t *item    = NULL;

    printf("{\n\n");
    for (int i = 0; i < size; ++i)
    {
        item = p_graph->adj_list[i];

        while (item != NULL)
        {
            if (item->weight == INT_MAX)
            {
                printf("vertex_weight[%d] -> INF\n", item->num_vertex);
            }
            else
            {
                printf("vertex_weight[%d] -> %d\n", item->num_vertex, item->weight);
            }

            item = item->next_node;
        } 
        printf("\n");   
    }
    printf("}\n\n");
}


void print_adj_matrix(adj_matrix_t *m)
{
    const int size = m->size;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            printf(" %d ", m->m[i][j]);
        
        printf("\n");
    }
    printf("\n");
}



void set_val_adj_matrix(adj_matrix_t *matrix, int **array_adj_list)
{
    const int size =matrix->size;

    for (int i = 0; i < size; ++i)
    {
        set_matrix_adj_list(matrix, i, array_adj_list[i]);
    }
}




void free_adj_matrix(adj_matrix_t *matrix)
{
    const int size = matrix->size;

    for (int i = 0; i < size; ++i)
    {
        free(matrix->m[i]);
    }

    free(matrix->m);
    free(matrix);

    matrix = NULL;
}



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
        printf("visited_vertex[%d] -> %d\n", i, p_graph->visited[i]);

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