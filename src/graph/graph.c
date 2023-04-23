#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "vertex_list.h"

graph_t *Graph_new() {
    graph_t *g = malloc(sizeof(graph_t));
    if (!g)
        return NULL;

    g->vl = VertexList_new();
    return g;
}

void Graph_delete(graph_t *g) {
    if (!g)
        return;

    VertexList_delete(g->vl);
    free(g);
}

void Graph_add_vertex(graph_t *g, char *name) {
    VertexList_add(g->vl, name);
}

void Graph_print(graph_t *g) {
    if (!g->vl->head) {
        printf("Empty graph...\n");
        return;
    }

    vertex_list_t *current = g->vl;
    while (current != NULL) {
        printf("%s", current->head->name);
        printf("\n|\nv\n");
        current = current->tail;
    }
}
