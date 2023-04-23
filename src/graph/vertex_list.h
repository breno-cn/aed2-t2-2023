#pragma once

#include "vertex.h"
#include "adjacency_list.h"

typedef struct vertex_list_t {
    vertex_t *head;
    adjacency_list_t *al;
    struct vertex_list_t *tail;
} vertex_list_t;

vertex_list_t *VertexList_new();
void VertexList_delete(vertex_list_t *vl);

vertex_list_t *VertexList_add(vertex_list_t *vl, char *name);
