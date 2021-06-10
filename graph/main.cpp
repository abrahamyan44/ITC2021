#include <iostream>
#include "Graph.h"

using namespace std;

int main () {
    Graph G(5);
    G.AddingEdge(0, 1, 15);
    G.AddingEdge(1, 2, 10);
    G.AddingEdge(3, 2, 3);
    G.AddingEdge(4, 3, 3);
    G.AddingEdge(3, 1, 2);
    G.AddingEdge(3, 0, 4);
    G.AddingEdge(2, 0, 5);
    G.AddingEdge(4, 1, 3);
    G.ImplementDijktrasAlgorithm(0);
    return 0;
}