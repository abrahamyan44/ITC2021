#include <iostream>
#include "GraphImplementation.hpp"

Graph::Graph(int quantity) {
    this->m_quantity = quantity;
    this->m_matrix = new int*[quantity];
    for (int i = 0; i < quantity; ++i) {
        m_matrix[i]  = new int[quantity];
        for (int j = 0; j < quantity; ++j) {
            m_matrix[i][j] = 0;
        }
    }
    this->m_visited = new bool[m_quantity];
    for (int i = 0; i < m_quantity; ++i) {
        m_visited[i] = false;
    }                                      


}

Graph::~Graph() {
    if (m_quantity != 0) {
        for (int i = 0; i < m_quantity; ++i) {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }
}

void Graph::AddEdge(int vertice1, int vertice2) {
    if (vertice1 < m_quantity && vertice2 < m_quantity && vertice1 >= 0 && vertice2 >= 0) {
        this->m_matrix[vertice1][vertice2] = 1;
        this->m_matrix[vertice2][vertice1] = 1;
    }
}

void Graph::ImplementingBreadthFirstSearch(int vertice) {
    bool* visited = new bool[m_quantity];
    for (int i = 0; i < m_quantity; ++i) {
        visited[i] = false;
    }
    queue<int> sequence;
    sequence.push(vertice);
    visited[vertice] = true;
    while (!sequence.empty()) {
        for (int i = 0; i < m_quantity; ++i) {
            if (m_matrix[sequence.front()][i] == 1 && visited[i] == false) {
                sequence.push(i);
                visited[i] = true;
            }
        }
        cout << sequence.front() << ' ';
        sequence.pop();
    }
        cout << endl;
}

void Graph::ImplementingDepthFirstSearch(int vertice) {
    m_visited[vertice] = true;
    cout << vertice << ' ';
    for (int i = 0; i < m_quantity; ++i) {
        if (m_matrix[vertice][i] == 1 && m_visited[i] == false) {
            ImplementingDepthFirstSearch(i);
        }
    }     
}

void Graph::Print() {
    for (int i = 0; i < m_quantity; ++i) {
        for (int j = 0; j < m_quantity; ++j) {
            cout << m_matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << "Create non-directed graph." << endl;
    int vertice_quantity;
    cout << "Enter quantity of vertices: ";
    cin >> vertice_quantity;
    Graph graph(vertice_quantity);
    int edge_quantity;
    cout << "Enter quantity of edges you want to create: ";
    cin >> edge_quantity;
    int vertice1;
    int vertice2;
    cout << "Add edges, separating vertices by space. Note, that vertice numbering begins from 0. " << endl;
    for (int i = 0; i < edge_quantity; ++i) {
        cin >> vertice1 >> vertice2;
        graph.AddEdge(vertice1, vertice2);
    }
    int your_vertex;
    cout << "Choose from which vertex you want to start: ";
    cin >> your_vertex;
    cout << "BFS:" << endl;
    graph.ImplementingBreadthFirstSearch(your_vertex);
    cout << "DFS:" << endl;
    graph.ImplementingDepthFirstSearch(your_vertex);
    cout << endl;
    cout << "Matrix:" << endl;
    graph.Print();

    return 0;
}
