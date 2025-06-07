#include<bits/stdc++.h>
using namespace std;

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
typedef long long ll;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628
#define MOD 1000000007

//------------------solution starts below------------------

// pode ser que tenha aresta multipla

vector<vector<int>> adj, loop_graph;
vector<bool> vis;

int t;
vector<int> tin;
vector<int> low;
vector<int> loops;
set<pair<int, int>> bridges;

void tarjan(int u, int p)
{    
    low[u] = tin[u] = t++; vis[u] = true;
    
    for(auto v: adj[u])
    {
        if(!vis[v]) // Not visited
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            // No back-edge covering u
            if(low[v] > tin[u])
                bridges.insert({u, v});
        }
        else // Visited
        {
            if(v == p) continue;
            
            low[u] = min(low[u], tin[v]);

            // Revisiting back-edge
            if(tin[v] > tin[u]) continue;

            //(u, v) is a back-edge
        }
    }
}

void dfs(int u, int p)
{
    //cout << "visitando " << u << endl;
    vis[u] = true;
    tin[u] = t++;

    for(auto v: loop_graph[u]) if(v != p)
    {
        if(vis[v] and tin[u] > tin[v])
        {
            //cout << "loop de " << u << " a " << v << endl;
            loops.push_back(tin[u]-tin[v]+1);
        }
        else if(!vis[v])
            dfs(v, u);
    }
}

void init(int n)
{
    adj.clear();
    adj.resize(n);

    loop_graph.clear();
    loop_graph.resize(n);

    vis.clear();
    vis.resize(n, false);

    t = 0;
    tin.clear();
    tin.resize(n, -1);

    low.clear();
    low.resize(n);
    low.assign(n, -1);

    bridges.clear();

    loops.clear();
}

int cases = 1;

void solve(ll tt)
{
    cout << "Case " << cases++ << ": ";
    int n, m; cin >> n >> m;
    init(n);

    for(int i = 0 ; i < m ; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tarjan(0, -1);


    for(int u = 0 ; u < n ; u++)
    {
        for(auto v: adj[u])
        {
            // Só entra no grafo se não for ponte
            if(bridges.find({u, v}) == bridges.end() and bridges.find({v, u}) == bridges.end() and tin[u] < tin[v])
            {
                //cout << u << " " << v << endl;
                loop_graph[u].push_back(v);
                loop_graph[v].push_back(u);
            }
        } 
    }

    vis.assign(n, false);
    t = 0;
    tin.assign(n, -1);

    for(int u = 0 ; u < n ; u++)
        if(!vis[u])
            dfs(u, -1);


    unsigned long long res = 1;
    for(unsigned long long e: loops)
        res *= e;
    cout << res << endl;
}

int main()
{
    optimize;
    ll tt=1;
    cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}