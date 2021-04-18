#include "graph.hpp"

Graph::Graph(int vertex)
    :m_vertex(vertex),
    m_graph(nullptr),
    m_vizited(nullptr)
{
    m_graph = new int*[m_vertex];
    for(int i = 0; i < m_vertex; ++i) {
        m_graph[i] = new int[m_vertex];
        for(int j = 0; j < m_vertex; ++j) {
            m_graph[i][j] = 0;
        }
    }
    m_vizited = new int[m_vertex];
    for(int i = 0; i < m_vertex; ++i) {
        m_vizited[i] = 0;
    }
}

void Graph::AddEdge(int vertex, int edge)
{
    m_graph[vertex][edge] = 1;
    m_graph[edge][vertex] = 1;
}

void Graph::DepthFirstSearch(int vertex)
{
    assert(vertex <= m_vertex);
    m_vizited[vertex] = 1;
    std::cout << vertex << " ";
    for(int i = 0; i < m_vertex; ++i) {
        if(m_graph[vertex][i] == 1 && m_vizited[i] == 0) {
            DepthFirstSearch(i);
        }
    }
}

void Graph::BreadthFirstSearch(int vertex)
{
    assert(vertex <= m_vertex);
    m_vizited[vertex] = 1;
    std::queue<int> graph_queue;
    graph_queue.push(vertex);
    while(!graph_queue.empty()) {
        int temp = graph_queue.front();
        std::cout << temp  << " ";
        graph_queue.pop();
        for(int i = 0; i < m_vertex; ++i) {
            for(int j = 0; j < m_vertex; ++j) {
                if(m_graph[i][j] == 1 && m_vizited[i] == 0) {
                    graph_queue.push(i);
                    m_vizited[i] = 1;
                }
            }
        }
    }

}

Graph::~Graph()
{
    if(m_vertex == 0) {
        return;
    }
    for(int i = 0; i < m_vertex; ++i) {
        delete [] m_graph[i];
    } delete [] m_graph;
    delete [] m_vizited;
}

void Graph::Print()
{
    for(int i = 0; i < m_vertex; ++i) {
        for(int j = 0; j < m_vertex; ++j) {
            std::cout << m_graph[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}

