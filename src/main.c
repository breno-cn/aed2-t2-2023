#include "graph/graph.h"

int main() {
    graph_t *g = Graph_new();

    Graph_print(g);
    Graph_add_vertex(g, "patrocinio");
    Graph_add_vertex(g, "uberlandia");
    Graph_print(g);

    Graph_delete(g);

    return 0;
}
