#include "graph.hpp"

int main()
{
    Graph graph(5);
    Graph graph1(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(0, 3);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 4);
    graph.AddEdge(3, 3);
    graph.AddEdge(4, 4);
    //graph.Print();
    graph.DepthFirstSearch(0);
	std::cout << std::endl;
    graph1.AddEdge(0, 1);
    graph1.AddEdge(0, 2);
    graph1.AddEdge(1, 2);
    graph1.AddEdge(2, 0);
    graph1.AddEdge(2, 3);
    graph1.AddEdge(3, 3);
    graph1.BreadthFirstSearch(2);
    return 0;
}

