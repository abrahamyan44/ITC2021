#include <iostream>
#include "Graph.h"

using namespace std;

int main () {
    Graph G(5);
    G.AddingEdge(0, 1);
    G.AddingEdge(0, 2);
    G.AddingEdge(0, 3);
    G.AddingEdge(4, 1);
    G.AddingEdge(2, 1);
    G.AddingEdge(3, 2);
    G.ImplementBFS(3);
    return 0;
}