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
        vl->al = AdjacencyList_new();
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
    new_node->al = AdjacencyList_new();
    vl->tail = new_node;

    return new_node;
}

vertex_list_t *VertexList_find(vertex_list_t *vl, char *name) {
    if (!vl)
        return NULL;

    vertex_list_t *current = vl;
    while (current) {
        printf("A\n");
        if (strcmp(current->head->name, name) == 0) {
            printf("B\n");
            // printf("--|%s|--\n", current->head->name);
            printf("C\n");
            return current;
        }

        current = current->tail;
    }

    return NULL;
}
