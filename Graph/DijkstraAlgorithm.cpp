#include <iostream>
#include <limits.h>

const int vertices_count = 9;

void PrintDistances (int distance[])
{
    for (int i = 0; i < vertices_count; i++) {
        std::cout << i + 1 << " -- " << distance[i] << std::endl;
    }
}

int FindMinimumDistance (int* distance, bool* visited_vertex)
{
    int minimum_index;
    int minimum_distance = INT_MAX;
    for (int i = 0; i < vertices_count; ++i) {
        if (visited_vertex[i] == false && distance[i] < minimum_distance) {
            minimum_index = i;
            minimum_distance = distance[i];
        }
    }
    return minimum_index;
}

void DijkstraAlgorithm (int graph[vertices_count][vertices_count], int current_vertex)
{
    int distance[vertices_count];
    bool visited_vertex[vertices_count];
    for (int i = 0; i < vertices_count; ++i) {
        distance[i] = INT_MAX;
        visited_vertex[i] = false;
    }
    distance[current_vertex - 1] = 0;
    for (int i = 0; i < vertices_count - 1; ++i) {
        int shortest_peak_index = FindMinimumDistance(distance, visited_vertex);
        visited_vertex[shortest_peak_index] = true;

        for (int j = 0; j < vertices_count; ++j) {
            if (!visited_vertex[j] && graph[shortest_peak_index][j] 
                    && distance[j] > distance[shortest_peak_index] + graph[shortest_peak_index][j] ) {
                distance[j] = distance[shortest_peak_index] + graph[shortest_peak_index][j];
            }
        }
    }
    printf("Vertices distance from %d vertex.\n",current_vertex);
    PrintDistances(distance);
}

int main()
{
    int vertex = 1;
    int graph[vertices_count][vertices_count] = {
                             //1  2  3  4  5  6  7  8  9
                      /* 1*/ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                      /* 2*/ { 4, 0, 8, 0, 0, 0, 0, 2, 0 },
                      /* 3*/ { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                      /* 4*/ { 0, 0, 7, 0, 9, 4, 0, 0, 0 },
                      /* 5*/ { 0, 0, 0, 9, 0, 5, 0, 0, 0 },
                      /* 6*/ { 0, 0, 4, 6, 5, 0, 2, 0, 0 },
                      /* 7*/ { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                      /* 8*/ { 8, 7, 0, 0, 0, 0, 1, 0, 7 },
                      /* 9*/ { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    DijkstraAlgorithm(graph, vertex);

}
