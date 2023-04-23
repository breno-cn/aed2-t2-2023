#pragma once
#include "vertex_list.h"

typedef struct {
    vertex_list_t *vl;
    
} graph_t;

graph_t *Graph_new();
void Graph_delete(graph_t *g);

vertex_list_t *Graph_add_vertex(graph_t *g, char *name);
void Graph_add_edge(graph_t *g, char *from, char *to, int distance, int toll);
void Graph_print(graph_t *g);