#include "Graph.hpp"

int main()
{
    const int count = 7;
    Graph graph(count);

    graph.AddEdge(0,1);
    graph.AddEdge(0,2);
    graph.AddEdge(1,3);
    graph.AddEdge(2,4);
    graph.AddEdge(2,5);
    graph.AddEdge(5,6);
    bool visited[count] = {false};
    graph.DepthFirstSearch(0, visited);
}
