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
	void BreadthFirstSearch(T start);
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
void Graph<T>::BreadthFirstSearch(T start)
{
	queue<T> graph_queue;
	graph_queue.push(start);
    m_visited[start] = true;
	while(!graph_queue.empty()) {
		T temp = graph_queue.front();
		cout << temp << "\t";
		graph_queue.pop();
		for(int i = 0; i < m_vertex; i++) {
			for(int j = 0; j < m_vertex; j++) {
				if(m_graph[i][j] == 1 && m_visited[i] == false) {
					graph_queue.push(i);
					m_visited[i] = true;
				}
			}
		}
	}
	cout << endl;
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
    graph.BreadthFirstSearch(0);

    return 0;
}
