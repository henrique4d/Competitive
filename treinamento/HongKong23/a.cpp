#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 2e5+10;

vector<ll> g[MAXN];
ll dp[MAXN];

int n;

bool compare(int a, int b){
    return dp[a] < dp[b];
}

void init(){
    for (int i=0; i<n+10; i++){
        dp[i] = 0;
        g[i].clear();
    }
}

ll dfs(int u){
    for (auto v:g[u]){
        dfs(v);
    }
    sort(g[u].begin(), g[u].end(), compare);
    int maior = 0;

    if (g[u].size()){
        dp[g[u].back()]--;
    }

    for (auto v:g[u]){
        maior = max((ll)maior,dp[v]);
    }
    return dp[u] = 1 + maior;
}

void solve(){
    cin >> n;
    int pai;
    init();
    for (int i=0; i<n; i++){
        cin >> pai;
        pai--;
        if (pai != -1){
            g[pai].push_back(i);
        }
    }

    cout << dfs(0) << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}