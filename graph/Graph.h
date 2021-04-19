#pragma once
#include <iostream>
#include <queue>
#include <set>

class Graph
{
private:
    int** m_vertice_matrix;
    int m_vertices_count;

    bool* CreateTableForShowPassedVertices();
    void ImplementDFSRecursive(int vertice, bool* is_vertice_passed);
    void ImplementDijktrasAlgorithmRecursive(int vertice, std::set<int>& visited, std::pair<int, int>* info);
    bool IsVerticeVisited(int vertice, std::set<int>& visited);

public:
    Graph(int count);

    ~Graph();

    void AddingEdge(int v, int w, int weight=1);

    void ImplementBFS(int vertice);

    void ImplementDFS(int vertice);

    void ImplementDijktrasAlgorithm(int vertice);
};


Graph::Graph(int count) 
    :m_vertices_count(count) {
    m_vertice_matrix = new int*[m_vertices_count];
    for (int i = 0; i < m_vertices_count; ++i) {
        m_vertice_matrix[i] = new int[m_vertices_count];
        for (int j = 0; j < m_vertices_count; ++j) {
            m_vertice_matrix[i][j] = false;
        }
    }
}

Graph::~Graph() {
    for(int i = 0; i < m_vertices_count; ++i) {
        delete[] m_vertice_matrix[i];
    }
    delete[] m_vertice_matrix;
}

void Graph::AddingEdge(int v, int w, int weight) {
    if (v < m_vertices_count && v >= 0 && w < m_vertices_count && w >= 0) {
        m_vertice_matrix[v][w] = weight;
        m_vertice_matrix[w][v] = weight;
    }

    return;
}

bool* Graph::CreateTableForShowPassedVertices() {
    bool* table = new bool[m_vertices_count];
    for (int i = 0; i < m_vertices_count; ++i) {
        table[i] = 0;
    }
    return table;
}

void Graph::ImplementBFS(int vertice) {
    if (vertice < 0 || vertice >= m_vertices_count) {
        return;
    }
    bool* is_vertice_passed = CreateTableForShowPassedVertices();
    std::queue<int> q;
    q.push(vertice);
    is_vertice_passed[vertice] = true;
    while (!q.empty()) {
        vertice = q.front();
        for (int i = 0; i < m_vertices_count; ++i) {
            if (m_vertice_matrix[vertice][i] > 0 && is_vertice_passed[i] == false) {
                q.push(i);
                is_vertice_passed[i] = true;
            }
        }
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";
}

void Graph::ImplementDFS(int vertice) {
    if (vertice < 0 || vertice >= m_vertices_count) {
        return;
    }
    bool* is_vertice_passed = CreateTableForShowPassedVertices();
    ImplementDFSRecursive(vertice, is_vertice_passed);
    std::cout << "\n";
}

void Graph::ImplementDFSRecursive(int vertice, bool* is_vertice_passed) {
    is_vertice_passed[vertice] = true;
    std::cout << vertice << " ";
    for (int i = 0; i < m_vertices_count; ++i) {
        if (m_vertice_matrix[vertice][i] > 0 && is_vertice_passed[i] == false) {
            ImplementDFSRecursive(i, is_vertice_passed);
        }
    }
}

void Graph::ImplementDijktrasAlgorithm(int vertice) {
    std::set<int> visited;
    std::pair<int, int>* info_table = new std::pair<int, int>[m_vertices_count];
    for (int i = 0; i < m_vertices_count; ++i) {
        info_table[i].first = -1;
        info_table[i].second = -1;
    }
    info_table[vertice].first = 0;
    ImplementDijktrasAlgorithmRecursive(vertice, visited, info_table);
    for (int i = 0; i < m_vertices_count; ++i) {
        std::cout << i << " " << info_table[i].first << " " << info_table[i].second << std::endl;
    }
}

void Graph::ImplementDijktrasAlgorithmRecursive(int vertice, std::set<int>& visited, std::pair<int, int>* info) {
    visited.insert(vertice);
    for (int i = 0; i < m_vertices_count; ++i) {
        if (m_vertice_matrix[vertice][i] > 0 && (info[i].first == -1 || m_vertice_matrix[vertice][i] + info[vertice].first < info[i].first)) {
            info[i].first = m_vertice_matrix[vertice][i] + info[vertice].first;
            info[i].second = vertice;
        }
    }
    
    while (1) {
        int min_value_index = -1;
        for (int i = 0; i < m_vertices_count; ++i) {
            if (info[i].first != -1 && !IsVerticeVisited(i, visited) && (min_value_index == -1 || info[i].first < info[min_value_index].first)) {
                min_value_index = i;
            }
        }
        if (min_value_index == -1) {
            break;
        }
        ImplementDijktrasAlgorithmRecursive(min_value_index, visited, info);
    }
}

bool Graph::IsVerticeVisited(int vertice, std::set<int>& visited) {
    auto it = visited.find(vertice);
    if (it != visited.end()) {
        return true;
    }
    return false;
}