#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;

const ll MAXN = 1e6;

map<pair<ll, string>, ll> m;
vector<ll> adj[MAXN];
ll dist[MAXN];
ll leaf[MAXN];
ll contfolhas = 0;

void dfs(int u, int p){
    dist[u] = 0;
    bool folha = true;

    for (auto v:adj[u]){
        if (v == p) continue;
        dfs(v, u);
        dist[u] += dist[v];
        leaf[u] += leaf[v];
        folha = false;
    }
    dist[u] += leaf[u];    
    if (folha){
        leaf[u] = 1;
        contfolhas++;
    }
}

ll resp = INFLL;

void dfsResp(int u, int p, ll val){
    bool folha = true;
    for (auto v:adj[u]){
        if (v == p) continue;
        folha = false;
        dfsResp(v, u, val - leaf[v] + contfolhas - leaf[v] );
    }
    if (!folha) resp = min(resp, val); 
}

int main(){
    int n;
    string s;
    string aux;
    ll contestado = 1;
    cin >> n;
    
    for (int i=0; i<n; i++){
        cin >> s;
        string last;
        for (char &c:s){
            if (c == '/') c = ' ';
        }
        stringstream ss(s);

        ll estado = 1;
        while (ss >> aux){
            last = aux;
            if (m.find({estado, aux}) == m.end()){
                m[{estado,aux}] = ++contestado;
                adj[estado].push_back(m[{estado,aux}]);
            }
            estado = m[{estado,aux}];
        }
        if (m[{estado,last}] == 0){
            m[{estado,last}] = ++contestado;
            adj[estado].push_back(m[{estado,last}]);
        }
    }
    dfs(1,0);
    dfsResp(1,0, dist[1]);
    cout << resp << endl;
}