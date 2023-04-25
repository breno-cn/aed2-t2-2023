#include <stdio.h>
#include "graph/graph.h"

int main() {
    graph_t *g = Graph_new();
    char *filepath = "data.txt";

    Graph_read_file(g, filepath);
    Graph_print(g);

    printf("\n\n");
    // Graph_routes_from(g, "Uberlandia-MG", ExhibitionMode_by_distance, 2);
    // Graph_routes_from(g, "Uberlândia-MG", ExhibitionMode_by_toll, 1);
    
    Graph_delete(g);

    return 0;
}
