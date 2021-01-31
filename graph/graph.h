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
    int         num_vertex;
    int         *visited;
    struct node **adj_list;
} graph_t;


typedef struct node
{
    int         vertex;
    struct node *next_node;
} node_t;


void    add_edge(graph_t* , int , int );
void    remove_edge(graph_t* , int , int );
void    print_graph(graph_t* );
void    print_adj_list(node_t* );
node_t* find_edge(graph_t* , int );
void    free_graph(graph_t* );


#endif // !_GRAPH_H_
