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

vertex_list_t *Graph_add_vertex(graph_t *g, char *name) {
    VertexList_add(g->vl, name);
}

void Graph_add_edge(graph_t *g, char *from, char *to, int distance, int toll) {
    vertex_list_t *from_vertex = Graph_add_vertex(g, from);
    Graph_add_vertex(g, to);

    AdjacencyList_add(from_vertex->al, to, distance, toll);
}

void Graph_print(graph_t *g) {
    if (!g->vl->head) {
        printf("Empty graph...\n");
        return;
    }

    vertex_list_t *current = g->vl;
    while (current != NULL) {
        printf("%s", current->head->name);
        adjacency_list_t *current_adj = current->al;
        while (current_adj != NULL) {
            if (current_adj->head != NULL) {
                printf(" -> (%s, %d, %d)", current_adj->head->name, current_adj->distance, current_adj->toll);
            }
            current_adj = current_adj->tail;
        }
        current = current->tail;
        if (current != NULL)
            printf("\n|\nv\n");
    }
}
