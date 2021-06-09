#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

template <class T>
class Graph
{
private:
	int m_vertex;
	int** m_graph;
	bool* m_visited;
public:
	Graph();
	Graph(int size);
	~Graph();
	void AddEdge(int first_vertex, int second_vertex);
	void DepthFirstSearch(T start);
};

template class Graph<int>;

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
    m_graph = new T*[m_vertex];

	for(int i = 0; i < m_vertex; ++i) {
		m_graph[i] = new T[m_vertex];
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
                delete m_graph[j];
        }
        delete m_graph;
	    delete m_visited;
}

template <class T>
void Graph<T>::AddEdge(int first_vertex, int second_vertex)
{
	m_graph[first_vertex][second_vertex] = 1;
	m_graph[second_vertex][first_vertex] = 1;
}

template <class T>
void Graph<T>::DepthFirstSearch(T start)
{
    m_visited[start] = 1;
    std::cout << start << " " << std::endl;
    for(int i = 0; i < m_vertex; ++i) {
        if(m_graph[start][i] == 1 && m_visited[i] == 0) {
            DepthFirstSearch(i);
        }
    }
}

int main()
{
    Graph<int> graph(8);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(4, 7);
    graph.DepthFirstSearch(0);

    return 0;
}
