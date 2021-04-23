#ifndef GRAPH_HPP
#define GRAPH_HPP


class Graph
{
private:
    int m_vertices;
    int** m_matrix;

public:
    Graph(int);
    ~Graph();
    void AddEdge(int, int);
    void DepthFirstSearch(int, bool*);
};

#endif  //GRAPH_HPP
