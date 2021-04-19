#include "graph.hpp"

template <class T>
Graph<T>::Graph()
{
	m_vertex = 0;
        m_graph = new int*[m_vertex];
	for(int i = 0; i < m_vertex; ++i) {
		m_graph[i] = new int[m_vertex];
	}
        m_visited = new bool[m_vertex];
}

template <class T>
Graph<T>::Graph(int size)
{
	m_vertex = size;
        m_graph = new int*[m_vertex];
	for(int i = 0; i < m_vertex; ++i) {
		m_graph[i] = new int[m_vertex];
		for(int j = 0; j < m_vertex; ++j) {
			m_graph[i][j] = 0;
		}
	}
        m_visited = new bool[m_vertex];
	for(int k = 0; k < m_vertex; ++k) {
		m_visited[k] = false; 
	}
}

template <class T>
Graph<T>::~Graph()
{
        for(int j = 0; j < m_vertex; ++j) {
                delete[] m_graph[j];
        }
        delete[] m_graph;
	delete[] m_visited;
}

template <class T>
void Graph<T>::AddEdge(T vertex1, T vertex2)
{
	m_graph[vertex1][vertex2] = 1;
	m_graph[vertex2][vertex1] = 1;
}

template <class T>
void Graph<T>::BreadthFirstSearch(T start)
{
	queue<T> graph_queue;
	graph_queue.push(start);
	while(!graph_queue.empty()) {
		T temp = graph_queue.front();
		cout << temp << "\t";
		graph_queue.pop();
		for(int i = 0; i < m_vertex; i++) {
			for(int j = 0; j < m_vertex; j++) {
				if(m_graph[i][j] == 1 && m_visited[i] == false)
			       	{
					graph_queue.push(i);
					m_visited[i] = true;
				}
			}
		}
	}
	cout << endl;
}

