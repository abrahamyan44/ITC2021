#pragma once

#include <iostream>
#include <cassert>

class Graph
{
private:
	bool** m_matrix; // Matrix of vertices
	int m_vertices;  // Count of vertices	
private:
	void Allocate();
	void Deallocate();

public:
	Graph(int count);    // User ctor
	~Graph(); 		  	 // Dtor
	Graph(const Graph&); // Copy ctor

	void AddEdge(int i, int j);    // Add edges
	void RemoveEdge(int i, int j); // Remove edges
	void DFS(int vertex); 		   // Depth First Search Algorithm
	void BFS(int vertex);		   // Breadth First Search Algorithm
		
	void Print();	  // Print the matrix	
};

