#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <cassert>
#include <queue>

class Graph
{
private:
    int m_vertex;
    int** m_graph;
    int* m_visited;
public:
    Graph();
    Graph(int vertex);
    ~Graph();
    void AddEdge(int vertex1, int vertex2);
    void DepthFirstSearch(int vertex);
    void BreadthFirstSearch(int vertex);
    void Print();
};

#endif


