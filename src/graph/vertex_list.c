#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex_list.h"
#include "adjacency_list.h"

vertex_list_t *VertexList_new() {
    vertex_list_t *vl = malloc(sizeof(vertex_list_t));
    if (!vl)
        return NULL;

    vl->head = NULL;
    vl->tail = NULL;
    vl->al = AdjacencyList_new();
    return vl;
}

void VertexList_delete(vertex_list_t *vl) {
    if (!vl)
        return;
    
    vertex_list_t *current = vl->tail;
    while (current != NULL) {
        current = current->tail;
        free(current);
    }

    AdjacencyList_delete(vl->al);
    free(vl);
}

vertex_list_t *VertexList_add(vertex_list_t *vl, char *name) {
    // primeiro vertice
    if (!vl->head) {
        vl->head = Vertex_new(name);
        vl->tail = NULL;
        return vl;
    }

    // busca se o vertice ja existe
    vertex_list_t *current = vl;
    while (current != NULL) {
        if (strcmp(current->head->name, name) == 0) {
            // vertice ja existe, nao fazer nada
            return current;
        }

        current = current->tail;
    }

    vertex_list_t *new_node = VertexList_new();
    new_node->head = Vertex_new(name);
    new_node->tail = vl->tail;
    vl->tail = new_node;

    return new_node;
}
