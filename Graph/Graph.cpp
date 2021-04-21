#include <iostream>
#include <limits.h>

const int vertices_count = 9;

void PrintDistances (int distance[])
{
    for (int i = 0; i < vertices_count; i++) {
        std::cout << i << "--" << distance[i] << std::endl;
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
    distance[current_vertex] = 0;
    for (int i = 0; i < vertices_count - 1; ++i) {
        int index_minimum_distance_vertex = FindMinimumDistance(distance, visited_vertex);
        visited_vertex[index_minimum_distance_vertex] = true;

        for (int j = 0; j < vertices_count; ++j) {
            if (!visited_vertex[j] && graph[index_minimum_distance_vertex][j] != 0 && distance[j] != INT_MAX 
                    && distance[j] > distance[index_minimum_distance_vertex] + graph[index_minimum_distance_vertex][j] ) {
                distance[j] = distance[index_minimum_distance_vertex] + graph[index_minimum_distance_vertex][j];
            }
        }

    }
    PrintDistances(distance);
}

int main()
{
    int vertex = 5;
    int graph[vertices_count][vertices_count] = { 
                        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 2, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 4, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 5, 0, 0, 0 },
                        { 0, 0, 4, 6, 5, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 7, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    DijkstraAlgorithm(graph, vertex);

}
