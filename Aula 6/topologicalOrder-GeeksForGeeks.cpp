// A C++ program to print topological
// sorting of a DAG
#include <bits/stdc++.h>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[],
							stack<int>& Stack);

public:
	// Constructor
	Graph(int V);

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
								stack<int>& Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack
	// which stores result
	Stack.push(v);
}

// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function
	// to store Topological
	// Sort starting from all
	// vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}

	delete [] visited;
}

// Driver Code
int main()
{
	// Create a graph given in the above diagram

    Graph g(10);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(7, 2);
    g.addEdge(4, 1);
    g.addEdge(2, 4);
    g.addEdge(3, 2);

	cout << "Following is a Topological Sort of the given "
			"graph \n";
    auto start = high_resolution_clock::now();

	// Function Call

	g.topologicalSort();

    // Stop measuring time
    auto stop = high_resolution_clock::now();
    // Calculate the duration of the execution
    auto duration = duration_cast<microseconds>(stop - start);
    // Print the duration in milliseconds
    printf("\n\nTempo de Execucao: %.6f ms\n", duration.count() / 1000.0);


	return 0;
}
