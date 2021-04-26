#pragma once
#include <iostream>
#include <queue>
using namespace std;

class Graph
{
private:
    int m_quantity;
    int** m_matrix;
    bool* m_visited;
public:
    Graph(int quantity);
    ~Graph();
    void AddEdge(int vertice1, int vertice2);
    void ImplementingBreadthFirstSearch(int vertice);
    void ImplementingDepthFirstSearch(int vertice);
    void Print();
};
