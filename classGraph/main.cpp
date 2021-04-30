#include "Graph.hpp"

int main()
{
	Graph G(6);

	G.Print();

	G.AddEdge(2,2);
	G.AddEdge(3,3);
	G.AddEdge(4,5);
	G.AddEdge(1,1);
	G.AddEdge(3,2);

	G.DFS(2,5);
	G.BFS(0,3);
//	G.Print();


	return 0;
}
