#include <iostream>
#include <limits.h>
using namespace std;

const int V = 9;

int MinDistance (int dist[], bool include_vertices[]) {
		int min = INT_MAX;
		int min_index;
		for(int i = 0; i < V; i++) {
			if(include_vertices[i] == false && dist[i] < min) {
				min = dist[i];
				min_index = i;
			}
		}
	return min_index;
}


void Print (int dist[]) {
	cout << "V \t dist[V]" << endl;
	for (int i = 0; i < V; i++) {
		cout << i << "\t \t" << dist[i] << endl;
   }	
}


void Dijkstra (int graph[V][V], int src) {
	int dist[V];
	bool include_vertices[V];

	for(int i = 0; i < V; i++) {
		dist[i] = INT_MAX;
		include_vertices[i] = false;
	}

	dist[src] = 0;

	for(int i = 0; i < V - 1; i++) {
		int u = MinDistance( dist, include_vertices);
		include_vertices[u] = true;

			for(int v = 0; v < V; v++){
				if(graph[u][v], !include_vertices[v], dist[u] != INT_MAX, dist[u] + graph[u][v] < dist[v]) {
	dist[v] = dist[u] + graph[u][v];
				}
			}
	}
	Print (dist);
}

int main() {
	  int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	Dijkstra(graph, 0);
}
