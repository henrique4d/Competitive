#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long ll;

const ll MAXN = 1e6+10;
vector<pair<int,int>> g[MAXN];
ll sz[MAXN];
ll cont[MAXN];
ll n;
ll maior = 0;
void set_size(int u, int p){
    sz[u] = 1;
    for (auto [v,e]:g[u]){
        if (v!=p){
            set_size(v,u);
            sz[u] += sz[v];
            cont[e] = sz[v]*(n-sz[v]);
            maior = max(maior, cont[e]);
        }
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
    set_size(0,-1);
    int cont_maior = 0;
    for (int i=0; i<=n; i++){
        cont_maior += cont[i] == maior;
    }
    cout << maior << " " << cont_maior << endl;

}

int main(){
    optimize;
    int T = 1;
    while(T--){
        solve();
    }
}