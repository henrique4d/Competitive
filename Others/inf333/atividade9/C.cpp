
// C++ program for implementation of Ford Fulkerson
// algorithm
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
 
// Number of vertices in given graph
#define V 38
 
/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}
 
int should_be = 0;
	
// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    int rGraph[V]
              [V]; // Residual graph where rGraph[i][j]
                   // indicates residual capacity of edge
                   // from i to j (if there is an edge. If
                   // rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
 
    int parent[V]; // This array is filled by BFS and to
                   // store path
 
    int max_flow = 0; // There is no flow initially
 
    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, s, t, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    //cout << max_flow << " " << rGraph[27][1] << endl;

    if (should_be != max_flow){
        cout << "!\n";
        return 0;
    }
    for (int i=27; i<37; i++){
        for (int j=1; j<=26; j++){
            //cout << i << " " << j << " "<< fordFulkerson(graph, i, j) << endl;
            if (rGraph[i][j] == 1 ){
			    cout <<char('A' + j-1);
                goto here;
            }
        }
        cout << '_';

        here:
        int asodifhaosdf;
    }
    cout << endl;

    return max_flow;
}

int main(){
    char aux;
        
	int graph[38][38];
	memset(graph, 0, sizeof(graph));

    for (int i=27; i<37; i++){
        graph[i][37] = 1;
	}
    char character;
        
    while (cin >> character){
        char aux;
        cin >> aux;
        char aux2[2];
        aux2[0] = aux;
        int quant = atoi(aux2);
		should_be += quant;
		graph[0][character-'A'+1] = quant;
        while (cin >> aux){
			if (aux == ';') break;
			aux2[0] = aux;
        	int pos = atoi(aux2);
        	//cout << aux << endl;
			graph[character-'A'+1][27 + pos] = 1;
		}
		cin.ignore();
		if (cin.peek() == '\n'){
			fordFulkerson(graph, 0, 37);
			should_be = 0;
            memset(graph, 0, sizeof(graph));
            for (int i=27; i<37; i++){
                graph[i][37] = 1;
            }
        }
    }

    fordFulkerson(graph, 0, 37);
		
}