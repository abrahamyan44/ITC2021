#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

template <class T>
class Graph
{
private:
	int m_vertex;
	int** m_graph;
	bool* m_visited;
public:
	Graph();
	Graph(int size);
	~Graph();
	void AddEdge(T vertex1, T vertex2);
	void BreadthFirstSearch(T start);
};

template class Graph<int>;
