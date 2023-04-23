#pragma once

#define NAME_LENGTH 128

typedef struct {
    char name[NAME_LENGTH];
} vertex_t;

vertex_t *Vertex_new(char *name);
void Vertex_delete(vertex_t *v);
