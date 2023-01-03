// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
								stack<int>& Stack)
{
	// Mark the current node as visited.
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);

	// Push current vertex to stack which stores result
	Stack.push(v);
}

vector<list<int>> neighbors;
vector<bool> visited2;
int cont = 0;

void dfs(int pos){
    //cout <<"posicao: " <<  pos << endl;
    //cout << neighbors.size() << " " << visited2.size() << endl;
    for (auto it = neighbors[pos].begin(); it!= neighbors[pos].end(); it++){
        if (!visited2[*it]){
            //cont++;
            visited2[*it] = true;
            dfs(*it);
        }
    }
}


// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
	stack<int> Stack;

	// Mark all the vertices as not visited
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to store Topological
	// Sort starting from all vertices one by one
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	// Print contents of stack
	while (Stack.empty() == false) {

        if (!visited2[Stack.top()]){
            dfs(Stack.top());
            cont++;    
        }
        //cout << "here" << endl;
        //cout << Stack.top() << " ";
		Stack.pop();
	}
}

// Driver program to test above functions
int main()
{
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n, k;
        cin >> n >> k;
        Graph g(n);
        int a,b;
        neighbors.resize(0);
        neighbors.resize(n);
        visited2.resize(0);
        visited2.resize(n, false);
        cont = 0;

        for (int i=0; i<k; i++){
            cin >> a >> b;
            a--;
            b--;
            //cout << a << " " << b << endl;
            g.addEdge(a,b);
            neighbors[a].push_back(b);
        }
       
        //cout << "Following is a Topological Sort of the given graph n";
        g.topologicalSort();
        //cout << endl;
        printf("Case %d: %d\n", l+1, cont);
        //cout << cont << endl;
    }
	// Create a graph given in the above diagram
	
	return 0;
}
