#include <bits/stdc++.h>
using namespace std;
// #define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"
typedef long long ll;

const ll MAXN = 1e6+10;
vector<pair<int,int>> g[MAXN];
bool vis[MAXN];
ll sz[MAXN];
int n;
ll cont[MAXN];
ll maior = 0;

int dfs(int u, int p){
    int resp = 0;
    for (auto [v,_]:g[u]){
        if (!vis[v] and v!=p){
            resp += dfs(v,u);
        }
    }
    return resp+1;
}

int find_size(int u, int p =-1){
    if (vis[u]) return 0;
    sz[u] = 1;
    for (auto [v,e]:g[u]){
        if (v!=p) sz[u] += find_size(v,u);
    }
    return sz[u];
}

int find_centroid(int u, int p, int n){
    for (auto [v,e]:g[u]){
        if (!vis[v] and v!=p and sz[v] > n/2) return find_centroid(v,u,n);
    }
    return u;
}

void init_centroid(int u=0, int p=-1){
    find_size(u);
    int c = find_centroid(u,-1, sz[u]);
    vis[c] = true;
    cout << "analisando para o centroid " << c << " " << sz[c] << endl;
    int sum_total = 0;
    for (auto [v,e]:g[c]){
        if (!vis[v] and v!=p){
            // dfs(v,c,c,e);
            // cont[e] += sz[v];
            cout << "sizes " << sz[c] << " " << sz[v] << endl;
            cout << v << " " << sz[v] << " " << e << endl;
            cont[e] += sz[v]*(sz[c]-sz[v]);
            maior = max(maior, cont[e]);
        }
    }

    for (auto [v,e]:g[c]){
        if (!vis[v] and v!=p)init_centroid(v,c);
    }
}

void solve(){
    cin >> n;
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    init_centroid();
    
    int cont_maior = 0;
    for (int i=0; i<n; i++){
        if (cont[i] == maior) cont_maior++;
        cout << i << " " << cont[i] << endl;
    }
    cout << maior << " " << cont_maior << endl;
}

int main(){
    // optimize;
    int T = 1;
    while(T--){
        solve();
    }
}