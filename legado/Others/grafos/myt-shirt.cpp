/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://shygypsy.com/tools/
 * LICENSE:
 *      http://shygypsy.com/tools/LICENSE.html
 * Copyright (c) 2006
 * Contact author:
 *      abednego at gmail.c0m
 **/

/****************
 * Maximum flow * (Dinic's on an adjacency list + matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency 
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - prevv contains the minimum cut. If prevv[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * RUNNING TIME:
 *      - O(n^3)
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission (Gives WA, but it's probably my graph building that's wrong)
 *      - Valladolid 563:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 **/

#include <bits/stdc++.h>
using namespace std;
// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
// If you fill adj[][] yourself, make sure to include both u->v and v->u.
int cap[NN][NN], deg[NN], adj[NN][NN];

// BFS stuff
int q[NN], prevv[NN];

int dinic( int n, int s, int t )
{
    int flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prevv, -1, sizeof( prevv ) );
        int qf = 0, qb = 0;
        prevv[q[qb++] = s] = -2;
        while( qb > qf && prevv[t] == -1 )
            for( int u = q[qf++], i = 0, v; i < deg[u]; i++ )
                if( prevv[v = adj[u][i]] == -1 && cap[u][v] )
                    prevv[q[qb++] = v] = u;

        // see if we're done
        if( prevv[t] == -1 ) break;

        // try finding more paths
        for( int z = 0; z < n; z++ ) if( cap[z][t] && prevv[z] != -1 )
        {
            int bot = cap[z][t];
            for( int v = z, u = prevv[v]; u >= 0; v = u, u = prevv[v] )
                bot = min(cap[u][v], bot);
            if( !bot ) continue;

            cap[z][t] -= bot;
            cap[t][z] += bot;
            for( int v = z, u = prevv[v]; u >= 0; v = u, u = prevv[v] )
            {
                cap[u][v] -= bot;
                cap[v][u] += bot;
            }
            flow += bot;
        }
    }

    return flow;
}

//----------------- EXAMPLE USAGE -----------------
int main()
{
    map<string, int> aux;
   
    aux["XXL"] = 1;
    aux["XL"] = 2;
    aux["L"] = 3;
    aux["M"] = 4;
    aux["S"] = 5;
    aux["XS"] = 6;
    
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int camisas, pessoas;
        cin >> camisas >> pessoas;
       
        // read a graph into cap[][]
        memset( cap, 0, sizeof( cap ) );
        int n = 8 + pessoas;
        int s, t, m;
        s = 0;
        t = 8+pessoas-1;
        m = pessoas;
        for (int i=0; i<m; i++){
            string tamanho1, tamanho2;
            cin >> tamanho1 >> tamanho2;
            cap[aux[tamanho1]][7+i] = 1;
            cap[aux[tamanho2]][7+i] = 1;
        }
        for (int i=1; i<=6; i++){
            cap[0][i] = camisas/6;
        }
        for (int i=7; i<8+pessoas-1; i++){
            cap[i][8+pessoas-1] = 1;
        }
        // init the adjacency list adj[][] from cap[][]
        memset( deg, 0, sizeof( deg ) );
        for( int u = 0; u < n; u++ )
            for( int v = 0; v < n; v++ ) if( cap[u][v] || cap[v][u] )
                adj[u][deg[u]++] = v;

        if (dinic(n,s,t) == pessoas){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        //printf( "%d\n", dinic( n, s, t ) );   
    }
    
}