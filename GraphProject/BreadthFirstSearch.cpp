#include <iostream>
#include <queue>

class Graph 
{
		int m_vertices;
		int** m_matrix;
		bool* m_visited;
		std::queue<int> m_temporary;
public :
		~Graph();
		Graph(int m_vertices);
		void AddEdge(int top, int adjacent);	
		void Print();
		void BFS(int top);
		int CountOfVertices();
};

void Graph::Print() {
	///////////////////////////////
	std::cout << "  ";
	for (int i = 1; i <= m_vertices; ++i) {
		std::cout << i << " ";
	}
	/////////////////////////////////
	std::cout << std::endl;
    for (int i = 0; i < m_vertices; ++i) {
		std::cout << i + 1 << "|";
        for(int j = 0; j < m_vertices; ++j) {
            std::cout << m_matrix[i][j] << " ";
        }
    std::cout << std::endl;
    }   
	std::cout << std::endl;    
}    

int Graph::CountOfVertices() {
	return m_vertices;
}

Graph::Graph(int m_vertices) {
	this->m_vertices = m_vertices;
	m_matrix = new int*[m_vertices];
	for (int i = 0; i < m_vertices; ++i){
		m_matrix[i] = new int[m_vertices];
		for (int j = 0; j < m_vertices; ++j) {
			m_matrix[i][j] = 0;
		}
	}
	m_visited = new bool(m_vertices);
	for (int i = 0; i < m_vertices; ++i) {
		m_visited[i] = false;
	}
}

Graph::~Graph(){
    delete [] m_visited;
    for (int i = 0; i < m_vertices; ++i) {
        delete [] m_matrix[i];
    }
    delete[] m_matrix;

}

void Graph::AddEdge(int	top, int adjacent) {
	m_matrix[top -1][adjacent - 1] = 1;
}

void Graph::BFS(int top) {
	m_temporary.push(top);
	m_visited[top - 1] = true;
	while (!m_temporary.empty()){
		for (int i = 0; i < m_vertices; ++i) {
			if (m_matrix[m_temporary.front() - 1][i] == 1 && m_visited[i] == false) {
				m_temporary.push(i + 1);
				m_visited[i] = true;
			}
		}
		std::cout << m_temporary.front() << " ";
		m_temporary.pop();
	}
}

int main() {
	Graph g(6);
	int n;
	g.Print();
	g.AddEdge(1, 2);
	g.AddEdge(2, 3);
	g.AddEdge(3, 4);
	g.AddEdge(4, 5);
	g.AddEdge(1, 3);
	g.AddEdge(4, 6);
	g.AddEdge(2, 4);
	g.Print();
	std::cout << "Please input top which from depth first search will be printed" << " " << "Top must be more or equal 1and less or equal " << g.CountOfVertices() << std::endl;
	std::cin >> n;
	if (n > g.CountOfVertices()){
		std::cout << "Wrong number of top" << std::endl;
	} else {
		g.BFS(n);
	}

	return 0;
}



























