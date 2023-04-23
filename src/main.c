#include "graph/graph.h"

int main() {
    graph_t *g = Graph_new();

    Graph_add_edge(g, "patrocinio", "uberlandia", 150, 10);
    Graph_add_edge(g, "uberlandia", "patrocinio", 150, 10);
    Graph_add_edge(g, "uberlandia", "uberaba", 100, 5);
    Graph_add_edge(g, "uberaba", "uberlandia", 100, 5);
    Graph_print(g);

    Graph_delete(g);

    return 0;
}
