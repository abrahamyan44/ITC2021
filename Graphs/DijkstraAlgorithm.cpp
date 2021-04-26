#include<iostream>
#include<climits>
#define V 4

int FindIndexOfNextVertex(int distance[], bool visited[])
{
    int min = INT_MAX, next_index;

    for (int j = 0; j < V; j++) {
        if (visited[j] == false && distance[j] <= min) {
            min = distance[j], next_index = j;
        }
    }
    return next_index;
}

void PrintSolution(int distance[])
{
    for(int i = 0; i < V; ++i) {
        std::cout << i << " " << distance[i] << std::endl;
    }
}

void Dijkstra(int graph[V][V], int start_point)
{
    int distance[V];
    bool visited[V];
    for(int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }

    distance[start_point] = 0;
    for(int k = 0; k < V - 1; k++) {
        int next_index = FindIndexOfNextVertex(distance, visited);
        visited[next_index] = true;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && graph[next_index][i] && distance[next_index] != INT_MAX 
                && distance[next_index] + graph[next_index][i] < distance[i]) {
            distance[i] = distance[next_index] + graph[next_index][i];
        }
    }
    }
    PrintSolution(distance);
}

int main()
{
    int graph[V][V] =
    { {0, 7, 2, 5},
      {7, 0, 2, 0},
      {2, 3, 0, 1},
      {5, 0, 1, 0} };

    Dijkstra(graph, 0);

    return 0;
}
