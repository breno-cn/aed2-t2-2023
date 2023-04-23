#pragma once

#include "vertex.h"

typedef struct vertex_list_t {
    vertex_t *head;
    struct vertex_list_t *tail;
} vertex_list_t;

vertex_list_t *VertexList_new();
void VertexList_delete(vertex_list_t *vl);

void VertexList_add(vertex_list_t *vl, char *name);
