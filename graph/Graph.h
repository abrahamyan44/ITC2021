#pragma once
#include <iostream>
#include <queue>

class Graph
{
private:
    bool** m_vertice_matrix;
    int m_vertices_count;

public:
    Graph (int count);

    ~Graph ();

    void AddingEdge (int v, int w);

    void ImplementBFS(int vertice) const;
};


Graph::Graph (int count) 
    :m_vertices_count(count) {
    m_vertice_matrix = new bool*[m_vertices_count];
    for (int i = 0; i < m_vertices_count; ++i) {
        m_vertice_matrix[i] = new bool[m_vertices_count];
        for (int j = 0; j < m_vertices_count; ++j) {
            m_vertice_matrix[i][j] = false;
        }
    }
}

Graph::~Graph () {
    for(int i = 0; i < m_vertices_count; ++i) {
        delete[] m_vertice_matrix[i];
    }
    delete[] m_vertice_matrix;
}

void Graph::AddingEdge (int v, int w) {
    if (v < m_vertices_count && v >= 0 && w < m_vertices_count && w >= 0) {
        m_vertice_matrix[v][w] = true;
        m_vertice_matrix[w][v] = true;
    }

    return;
}

void Graph::ImplementBFS (int vertice) const {
    if (vertice < 0 || vertice >= m_vertices_count) {
        return;
    }
    bool* is_vertice_passed = new bool[m_vertices_count];
    for (int i = 0; i < m_vertices_count; ++i) {
        is_vertice_passed[i] = false;
    }
    std::queue<int> q;
    q.push(vertice);
    is_vertice_passed[vertice] = true;
    while (!q.empty()) {
        vertice = q.front();
        for (int i = 0; i < m_vertices_count; ++i) {
            if (m_vertice_matrix[vertice][i] == true && is_vertice_passed[i] == false) {
                q.push(i);
                is_vertice_passed[i] = true;
            }
        }
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}