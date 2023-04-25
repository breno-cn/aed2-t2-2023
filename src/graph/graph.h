#pragma once

#include "vertex_list.h"

typedef struct {
    vertex_list_t *vl;
} graph_t;

typedef enum {
    ExhibitionMode_by_distance, ExhibitionMode_by_toll
} RouteExhibitionMode;

extern graph_t *Graph_new();
extern void Graph_delete(graph_t *g);
extern void Graph_read_file(graph_t *g, char *filepath);

extern vertex_list_t *Graph_add_vertex(graph_t *g, char *name);
extern void Graph_add_edge(graph_t *g, char *from, char *to, int distance, int toll);
extern void Graph_routes_from(graph_t *g, char *from, RouteExhibitionMode mode, int max_steps);
extern void Graph_print(graph_t *g);

static void _Graph_routes_from(graph_t *g, vertex_list_t *from, RouteExhibitionMode mode, int current_step, int max_step);
