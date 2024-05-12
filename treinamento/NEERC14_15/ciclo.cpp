#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5+10;
vector<ll> g[MAXN];
bool visited[MAXN];
int n,m,a,b;

bool dfs(int u){
    bool possible = g[u].size() == 2;

    visited[u] = true;
    
    for (auto v:g[u])if(!visited[v]){
        if (!dfs(v)) possible = false;
    }

    return possible;
}

void solve(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll resp = 0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            resp += dfs(i);
        }
    }
    cout << resp << endl;
}

int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}