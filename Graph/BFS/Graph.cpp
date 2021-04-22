#include <iostream>
#include <vector>
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

void Graph::BreadthFirstSearch (int first)
{
    int visited[m_vertices] = {false};
    std::vector<int> stored_nodes;
    stored_nodes.push_back(first);
    visited[first] = true;
    int visited_item;
    while(!stored_nodes.empty()) {
        visited_item = stored_nodes[0];
        std::cout << visited_item << " ";
        stored_nodes.erase(stored_nodes.begin());
        for (int column = 0; column < m_vertices; ++column) {
            if (1 == m_matrix[visited_item][column] && (!visited[column])) {
                stored_nodes.push_back(column);
                visited[column] = true;
            }
        }
    }
}

