#include <iostream>
#include "Graph.hpp"

Graph::Graph (int vertices)
    :m_vertices(vertices)
{
    m_matrix = new int*[m_vertices];
    for (int i = 0; i < m_vertices; ++i) {
        m_matrix[i] = new int[m_vertices];
        for (int j = 0; j < m_vertices; ++j) {
            m_matrix[i][j] = 0;
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < m_vertices; ++i) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

void Graph::AddEdge (int start, int end)
{
    m_matrix[start][end] = 1;
    m_matrix[end][start] = 1;
}

void Graph::DepthFirstSearch (int first, bool* visited)
{
    std::cout << first << " ";
    visited[first] = true;
    for (int column = 0; column < m_vertices; ++column) {
        if (1 == m_matrix[first][column] && (!visited[column])) {
            DepthFirstSearch(column, visited);
        }
    }
}

