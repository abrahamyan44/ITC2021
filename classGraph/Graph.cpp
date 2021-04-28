#include "Graph.hpp"

Graph::Graph(int count)
	: m_matrix(nullptr)
	, m_vertices(count) {
	Allocate();
	
	assert(count == m_vertices);
}

Graph::Graph(const Graph& G) 
	: m_matrix(G.m_matrix)
	, m_vertices(G.m_vertices) {
	Allocate();

	for (int i = 0; i < m_vertices; ++i) {
		for (int j = 0; j < m_vertices; ++j) {
			assert(0 != m_matrix);
			m_matrix[i][j] = G.m_matrix[i][j];
		}
	}

		assert(0 != m_vertices);
		assert(m_vertices == G.m_vertices);
}

Graph::~Graph() {
	if (0 == m_vertices) {
		assert(0 == m_matrix);
		return;
	}

	Deallocate();
}

void Graph::AddEdge(int i, int j) {
	m_matrix[i][j] = true;
	m_matrix[j][i] = true;
}

void Graph::RemoveEdge(int i, int j) {
	m_matrix[i][j] = false;
	m_matrix[j][i] = false;
}

void Graph::Print() {
	for (int i = 0; i < m_vertices; ++i) {
		std::cout << i << " : ";	
		for (int j = 0; j < m_vertices; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
		std::cout << std::endl;
}

void Graph::Allocate() {
	m_matrix = new bool*[m_vertices];

	for (int i = 0; i < m_vertices; ++i) {
		m_matrix[i] = new bool[m_vertices];
	}
}

void Graph::Deallocate() {	
	for (int i = 0; i < m_vertices; ++i) {
		delete[] m_matrix[i];
	}

	delete[] m_matrix;
	m_matrix = 0;
	m_vertices = 0;
}
