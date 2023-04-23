#include <stdlib.h>
#include <string.h>

#include "vertex.h"

vertex_t *Vertex_new(char* name) {
    vertex_t *v = malloc(sizeof(vertex_t));
    if (!v)
        return NULL;

    strcpy(v->name, name);
    return v;
}

void Vertex_delete(vertex_t *v) {
    if (v)
        free(v);
}
