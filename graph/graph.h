#ifndef _GRAPH_H_
#define _GRAPH_H_

#define _IS_NOT_VISIED_ ( 0 ) 
#define _VISITED_       ( 1 )

struct graph;
struct node;

/* 
    vertex      - вершина
    edge        - ребро
    adjacency   - смежность
*/

typedef struct graph
{
    int         count_vertex;
    int         *visited;
    struct node **adj_list;
} graph_t;


typedef struct node
{
    int         num_vertex;
    struct node *next_node;
} node_t;



void    dfs(graph_t* , int );
void    bfs(graph_t* , int );


void    add_adj_list(graph_t* , int , int* , int );
node_t* add_edge(graph_t* , int , int );

node_t* remove_edge(graph_t* , int , int );

void    set_visited_val(graph_t* , int );

void    print_visited(graph_t* );
void    print_graph(graph_t* );
void    print_adj_list(node_t* );

node_t* find_edge(graph_t* , int );

void    free_graph(graph_t* );
void    free_adj_list(node_t* );


#endif // !_GRAPH_H_
