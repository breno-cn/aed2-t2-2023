#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "vertex_list.h"

#define LINE_SIZE 256

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

void Graph_read_file(graph_t *g, char *filepath) {
    FILE *file = fopen(filepath, "r");

    char line[LINE_SIZE];
    while (fgets(line, LINE_SIZE, file)) {
        char *from = strtok(line, " ");
        char *to = strtok(NULL, " ");
        int distance = atoi(strtok(NULL, " "));
        int toll = atoi(strtok(NULL, " "));

        Graph_add_edge(g, from, to, distance, toll);
    }

    fclose(file);
}

vertex_list_t *Graph_add_vertex(graph_t *g, char *name) {
    VertexList_add(g->vl, name);
}

void Graph_add_edge(graph_t *g, char *from, char *to, int distance, int toll) {
    vertex_list_t *from_vertex = Graph_add_vertex(g, from);
    vertex_list_t *to_vertex = Graph_add_vertex(g, to);

    AdjacencyList_add(from_vertex->al, to_vertex, distance, toll);
    AdjacencyList_add(to_vertex->al, from_vertex, distance, toll);
}

void Graph_routes_from(graph_t *g, char *from, RouteExhibitionMode mode, int max_steps) {
    vertex_list_t *start = VertexList_find(g->vl, from);

    // _Graph_routes_from(g, start, mode, 0, max_steps);
    adjacency_list_t *current_node = start->al;
    printf("|%p|", current_node->head);
    // if (!current_node->head)
        // return;

    while (current_node) {
        _Graph_routes_from(g, current_node->head, mode, 0, max_steps);
    }
}

static void _Graph_routes_from(graph_t *g, vertex_list_t *from, RouteExhibitionMode mode, int current_step, int max_steps) {
    if (current_step >= max_steps)
        return;

    printf("%s -> ", from->head->name);
    adjacency_list_t *current_node = from->al;
    if (!current_node->head)
        return;

    while (current_node) {
        _Graph_routes_from(g, current_node->head, mode, current_step + 1, max_steps);
    }
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
                printf(" -> (%s, %d km, $RS %d)", current_adj->head->head->name, current_adj->distance, current_adj->toll);
            }
            current_adj = current_adj->tail;
        }
        current = current->tail;
        if (current != NULL)
            printf("\n|\nv\n");
    }
}
