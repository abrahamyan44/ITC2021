#include <iostream>
#include "Graph.h"

using namespace std;

int main () {
    Graph G(5);
    G.AddingEdge(0, 1);
    G.AddingEdge(0, 2);
    G.AddingEdge(4, 0);
    G.AddingEdge(3, 1);
    G.ImplementBFS(2);
    G.ImplementDFS(0);
    return 0;
}