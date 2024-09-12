#include <limits.h>
#include <iostream>

#define VERTECES 4

int MinDistance(int distances[], bool visited[]){
	int min = INT_MAX;
	int min_index;
	for (int i = 0; i < VERTECES; ++i) {
		if (visited[i] == false && distances[i] <= min) {
			min = distances[i];
			min_index = i;
		}
	}
	return min_index;
}

void Print(int distances[]) {
	std::cout << "Vertex  Distance from Source\n";
	for (int i = 0; i < VERTECES; ++i)
		std::cout << i << "  " << distances[i] << std::endl;
}

void Dijkstra(int graph[VERTECES][VERTECES], int source) {
	int distances[VERTECES];
	bool visited[VERTECES]; 
	for (int i = 0; i < VERTECES; ++i) {
		distances[i] = INT_MAX;
		visited[i] = false;
	}
	distances[source] = 0;
	for (int count = 0; count < VERTECES - 1; ++count) {
		int u = MinDistance(distances, visited);
		visited[u] = true;
		for (int v = 0; v < VERTECES; ++v)
			if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
				distances[v] = distances[u] + graph[u][v];
			}
	}

	Print(distances);
}

int main() {
	int graph[VERTECES][VERTECES] = 
						{ { 0, 4, 0, 0 },
						{ 4, 0, 8, 0 },
						{ 0, 8, 0, 7 },
						{ 0, 0, 7, 0 } };
	Dijkstra(graph, 0);

	return 0;
}
