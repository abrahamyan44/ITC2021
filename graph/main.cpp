#include "graph.hpp"

int main() 
{
Graph<int> graph(7);
graph.AddEdge(1, 5);
graph.AddEdge(2, 6);
graph.AddEdge(4, 3);
graph.AddEdge(3, 2);
graph.BreadthFirstSearch(4);
}
