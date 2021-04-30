#pragma once

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>

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
	bool IsConnected(int i, int j);// Check if 2 vertices are connected 
	void DFS(int start, int end); 		   // Depth First Search Algorithm
	void BFS(int start, int end);		   // Breadth First Search Algorithm
		
	void Print();	  // Print the matrix	
};

