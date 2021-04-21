#include <iostream>
#include <stdio.h>
#include <limits.h> //for INT_MAX
#include <vector>   //for vector

typedef std::vector< std::vector<int> > Matrix;

void PrintSolution(int* dist, int size)
{
  	std::cout << "DISTANCES." << std::endl;
  	
	for (int i = 0; i < size; i++) {
		std::cout << i << "    " << dist[i] << std::endl;
	}
}

int minDistance(int* distance, bool* visited, int size)
{
    int min = INT_MAX, min_index;
  
    for (int i = 0; i < size; i++) {
        if (false == visited[i] && distance[i] <= min) {
            min = distance[i];
		   	min_index = i;
		}
	}
  
    return min_index;
}

void DijkstraSort(Matrix& graph, int src)
{
    int distance[graph.size()];  // distance from src to i  
    bool visited[graph.size()];  // current shortest distance from src to i is finalized
  
    for (int i = 0; i < graph.size(); i++) {
        distance[i] = INT_MAX;
	   	visited[i] = false;
	}
  
    distance[src] = 0; // Distance of source vertex from itself is always 0
  
    // Find shortest path for all vertices
    for (int count = 0; count < graph.size() - 1; count++) {
        int u = minDistance(distance, visited, graph.size());	 
        visited[u] = true;          
		for (int v = 0; v < graph.size(); v++) {
            if (false == visited[v] && graph[u][v] &&
				distance[u] != INT_MAX && 
				distance[v] > distance[u] + graph[u][v]) {
                distance[v] = distance[u] + graph[u][v];
			}
		}
	}  

	PrintSolution(distance, graph.size());
}

int main()
{
	Matrix m =	{ { 0, 1, 0, 3, 1},
				  { 1, 0, 5, 0, 0},
              	  { 0, 5, 0, 2, 1},
              	  { 3, 0, 2, 0, 6},
              	  { 1, 0, 1, 6, 0} };
					 
	DijkstraSort(m, 0);

	return 0;
}
