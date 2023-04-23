#pragma once

#include "vertex.h"

typedef struct adjacency_list_t {
    vertex_t *head;
    int distance;
    int toll;
    struct adjacency_list_t *tail;
} adjacency_list_t;

adjacency_list_t *AdjacencyList_new();
void AdjacencyList_delete(adjacency_list_t *al);

void AdjacencyList_add(adjacency_list_t *al, char *to, int distance, int toll);
