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

vector<vector<pair<int, int>>> adj, mst; // Grafo original e arvore geradora maxima
vector<pair<pair<int, int>, int>> usedEdges; // Vértices usados na arvore geradora máxima
int prim(int start=0)
{
    int n = adj.size();
 
    int totalWeight = 0; 
    int numTaken = 0; // Number of nodes taken
 
    vector<bool> taken(n, false); // Stores for every node, if it was taken
    priority_queue<pair<int, pair<int, int>>> pq;
 
    pq.push({0, {start, start}});
 
    while (!pq.empty() and numTaken < n)
    {
        int w1 = pq.top().first;
        int u = pq.top().second.first;
        int p = pq.top().second.second;
        pq.pop();
        if(taken[u]) continue;
 
        if(u != p)
            usedEdges.push_back({{u, p}, w1});
 
        taken[u] = true;
        numTaken++;
        totalWeight += w1;
 
        for(auto [v, w2]: adj[u])
            if(!taken[v])
            {
                pq.push({w2, {v, u}});
            }     
    }
 
    return totalWeight;
}

struct Binary_Lifting
{
    vector<vector<pair<int, int>>> ancestor; // acestor[node][i] guarda o par com o 2^i - ésimo ancestral de node e a aresta minima no caminho até ele
    vector<int> depth; // Profundidade de cada nodo
    vector<pair<int, int>> parent; // parent[i] é o pai de i e a aresta entre eles

    int n; // Tamanho do grafo
    int l; // log2(n) + 1 

    // Carrega o 1o ancestral de cada nodo e calcula a profundidade de cada nodo
    void dfs(int curr, int p, int currDeph)
    {
        int minEdge;
        
        minEdge = parent[curr].second;
            
        ancestor[curr][0] = {p, minEdge};
        depth[curr] = currDeph;
        for(auto e: mst[curr]) if(e.first != p)
        {
            parent[e.first] = {curr, e.second};
            dfs(e.first, curr, currDeph+1);
        }
            
    }
    
    // Carrega ancestor
    Binary_Lifting(int n): n(n)
    {
        depth.resize(n);
        parent.resize(n);
        parent[0] = {-1, INF};
        l = 25;

        ancestor.resize(n, vector<pair<int, int>>(l, {-1, -1}));

        dfs(0, -1, 0); // Carrega o 1o ancestral de cada nodo

        // Carrega todos os outros ancestrais
        for(int i = 1 ; i < l ; i++)
        {
            for(int node = 0 ; node < n ; node++)
            {
                int a = ancestor[node][i-1].first; // 2^i-1 ésimo ancestral
                int minimum = ancestor[node][i-1].second; // aresta minima entre node e seu 2^i-1 ésimo ancestral
                if(a != -1)
                {
                    ancestor[node][i].second = min(minimum, ancestor[a][i-1].second);
                    ancestor[node][i].first = ancestor[a][i-1].first;
                }
                    
            }
        }
    }

    // Retorna o k-ésimo ancestral de node
    int kth_ancestor(int node, int k)
    {
        for(int i = l-1 ; i >= 0  ; i--)
        {
            if((1 << i) & k)
            {
                if(ancestor[node][i].first == -1)
                    return -1;
                
                node = ancestor[node][i].first;
            } 
        }
        return node;
    }

    // Retorna a resta minima entre u e v se v for antecessor de u
    int min_edge_ancestor(int u, int v, int up)
    {
        if(up == -1)
            up = depth[u] - depth[v];

        int res = INF;
        for(int i = l-1 ; i >= 0 ; i--)
        {
            if(up & (1 << i))
            {
                res = min(res, ancestor[u][i].second);
                u = ancestor[u][i].first;
                up -= (1<<i);
            }
        }
        return res;
    }

    int min_edge(int u, int v)
    {
        int sameDepthAncestor, up;
        if(depth[u] != depth[v])
        {
            if(depth[u] < depth[v])
                swap(u, v);
            
            up = depth[u] - depth[v];
            sameDepthAncestor = kth_ancestor(u, up);
        }
        else
            sameDepthAncestor = -1;

        if(sameDepthAncestor == v) // Acha menor aresta de u ate v
        {
            return min_edge_ancestor(u, v, up);
        }
        else // Acha a menor aresta de u ate lca(u,v) ate v
        {
            int mid = lca(u, v);
            return min(min_edge_ancestor(u, mid, -1), min_edge_ancestor(v, mid, -1));
        }
    }

    // Retorna o ancestral comum de u e v
    int lca(int u, int v)
    {
        // Deixa u e v na mesma profundidade
        if(depth[u] != depth[v])
        {
            if(depth[u] < depth[v])
                swap(u, v);
            
            int up = depth[u] - depth[v];
            u = kth_ancestor(u, up);
        }

        // Se eles forem iguais, um é ancestral do outro
        if(u == v)
            return u;
        
        int uAncestor, vAncestor;
        for(int i = l-1 ; i >= 0 ; i--) // Sobe 2^i niveis na arvore enquanto a nova posicao for diferente para u e v
        {
            uAncestor = ancestor[u][i].first; 
            vAncestor = ancestor[v][i].first;
            if(uAncestor != vAncestor)
            {
                u = uAncestor;
                v = vAncestor;
            }
        }
        return ancestor[u][0].first; // Retorna a posição acima
    }
};

void solve(int tt)
{
    int n, m, s; cin >> n >> m >> s;
    adj.resize(n);

    // Leitura do grafo
    int u, v; int w;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> u >> v >> w; u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Carrega o grafo da arvore geradora máxima
    prim();
    mst.resize(n);
    for(auto e: usedEdges)
    {
        u = e.first.first; v = e.first.second;
        w = e.second;

        mst[u].push_back({v, w});
        mst[v].push_back({u, w});
    }

    // Carrega os dados da binary lifting
    Binary_Lifting b(n);

    // Queires
    for(int i = 0 ; i < s ; i++)
    {
        cin >> u >> v;
        u--; v--;
        cout << b.min_edge(u, v) << endl;
    }        
}

int main()
{
    optimize;
    int tt=1;
    //cin >> tt;
    while(tt--) solve(tt);
    //while(cin >> tt && tt) solve(tt);

    return 0;
}