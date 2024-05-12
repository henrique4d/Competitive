#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 10;

ll tab[MAXN][MAXN];

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};

void solve(){
    int n;
    cin >> n;
    int proxima = 0;
    
    vector<pair<ll,ll>> resp;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> tab[i][j];
            tab[i][j]--;
        }
    }
    dsu d(n+10);
    for (int j=0; j<n; j++){
        for (int i=0; i<n; i++){
            if (d.find(i) != d.find(tab[i][j])){
                resp.push_back({i, tab[i][j]});
                d.unite(i, tab[i][j]);
            }
        }
    }
    for (int i=0; i<resp.size(); i++){
        cout << resp[i].first+1 << " " << resp[i].second+1 << endl;
    }
    cout << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}