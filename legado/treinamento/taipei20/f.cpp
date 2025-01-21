#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 3e5+10;
vector<ll> g[MAX];
bool switc[MAX];
bool visited[MAX];

ll resp = 0;

void dfs(int u, int p){
    visited[u] = true;
    for (auto v:g[u]) if (v!=p){
        dfs(v,u);
        if (!switc[v]){
			if (!switc[u]) resp++;
			switc[u] = true;
		}
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    int a,b;
    for (int i=0; i<n+m; i++){
        cin >> a >> b;
        if (a >= n or b >= n){
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
	vector<int> ciclo;
    for (int i=0; i<n; i++){
        dfs(i,-1);
		if (switc[i]) ciclo.push_back(i);
    }
	if(!ciclo.size()){
		resp += (n+1)/2;
	}
	else{
		for (int i=0; i<ciclo.size()-1; i++){
			resp += (ciclo[i+1] - ciclo[i] - 1)/2;
		}
		resp += (n-ciclo.back() + ciclo.front()-1)/2;
	}
	cout << resp << endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}