#include <stdio.h>
#include <stdlib.h>

#include "adjacency_list.h"
#include "vertex.h"

adjacency_list_t *AdjacencyList_new() {
    adjacency_list_t *al = malloc(sizeof(adjacency_list_t));
    if (!al)
        return NULL;

    al->head = NULL;
    return al;
}

void AdjacencyList_delete(adjacency_list_t *al) {
    if (!al)
        return;

    if (!al->head) {
        free(al);
        return;
    }

    adjacency_list_t *current = al->tail;
    while (current != NULL) {
        adjacency_list_t *tmp = current;
        current = current->tail;
        free(tmp);
    }

    free(al);
}

void AdjacencyList_add(adjacency_list_t *al, char *to, int distance, int toll) {
    adjacency_list_t *new_node = AdjacencyList_new();
    new_node->head = Vertex_new(to);
    new_node->distance = distance;
    new_node->toll = toll;

    // al->tail = new_node;
    new_node->tail = al->tail;
    al->tail = new_node;
}
