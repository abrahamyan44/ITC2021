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
	if (j < 0 || i < 0 || j > m_vertices || i > m_vertices) {
		std::cout << "Error: index out of bounds.";
	}

	m_matrix[i][j] = true;
	m_matrix[j][i] = true;
}

void Graph::RemoveEdge(int i, int j) {
	if (j < 0 || i < 0 || j > m_vertices || i > m_vertices) {
		std::cout << "Error: index out of bounds.";
	}

	m_matrix[i][j] = false;
	m_matrix[j][i] = false;
}

bool Graph::IsConnected(int i, int j) {
	return m_matrix[i][j] == 1;
}

void Graph::DFS(int start, int end) {
	if (start == end) {
		return;
	}

	std::stack<int> s{ };
	bool* visited = new bool[m_vertices]; // array to represent which vertices we've visited

	for (int i = 0; i < m_vertices; ++i) {
		visited[i] == false;
	}

	s.push(start);
    visited[start] = true; // mark node as visited	

	std::cout << "Depth first search starting from point: " << start << std::endl;

	while (!s.empty()) {
		int current = s.top();
		s.pop();

		if (current == end) {
			break;		
		}

		std::cout << current << " ";

		for (int i = m_vertices; i >= 0; --i) {
			if (IsConnected(current,i) && !visited[i]) { 
				// if they're connected and we haven't visited it yet
				s.push(i);
				visited[i] = true;
			}
		}			
	}
	std::cout << end << std::endl;
	delete[] visited;
}

void Graph::BFS(int start, int end) {
	if (start == end) {
		return;
	}

	bool* visited = new bool[m_vertices]; // array to represent which vertices we've visited
	std::queue<int> q{ };
	
	for (int i = 0; i < m_vertices; ++i) {
		visited[i] == false;
	}

	visited[start] = true; 			  // mark node as visited	
	q.push(start);

	std::cout << "Breadth first search starting from point: " << start << std::endl;
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == end) {
			break;		
		}

		std::cout << current << " ";

		for (int i = m_vertices; i >= 0; --i) {
			if (IsConnected(current,i) && !visited[i]) { 
				// if they're connected and we haven't visited it yet
				q.push(i);
				visited[i] = true;
			}
		}			
	}
	std::cout << end << std::endl;
	delete[] visited;
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
