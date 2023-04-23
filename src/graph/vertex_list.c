#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex_list.h"

vertex_list_t *VertexList_new() {
    vertex_list_t *vl = malloc(sizeof(vertex_list_t));
    if (!vl)
        return NULL;

    vl->head = NULL;
    vl->tail = NULL;
    return vl;
}

void VertexList_delete(vertex_list_t *vl) {
    if (!vl)
        return;
    
    vertex_list_t *current = vl->tail;
    while (vl != NULL) {
        current = vl;
        vl = vl->tail;
        free(current);
    }

    free(vl);
}

void VertexList_add(vertex_list_t *vl, char *name) {
    // first vertex to add
    if (!vl->head) {
        vl->head = Vertex_new(name);
        return;
    }

    // search if the vertex has already ben added
    vertex_list_t *current = vl;
    while (current != NULL) {
        if (strcmp(current->head->name, name) == 0) {
            // vertice ja existe, nao fazer nada
            return;
        }

        current = current->tail;
    }

    vertex_t *new_vertex = Vertex_new(name);
    vertex_list_t *new_node = VertexList_new();
    new_node->head = new_vertex;
    vl->tail = new_node;
}
