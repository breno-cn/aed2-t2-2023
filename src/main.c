#include "graph/graph.h"

int main() {
    graph_t *g = Graph_new();
    char *filepath = "data.txt";

    Graph_read_file(g, filepath);
    Graph_print(g);
    
    Graph_delete(g);

    return 0;
}
