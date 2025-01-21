#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    int n,m;
    cin >> n >> m;
    dsu d(n+10);
    for (int i=0; i<m; i++){
        int tam;
        cin >> tam;
        int last = -1;
        int x;
        for (int j=0; j<tam; j++){
            cin >> x;
            if (j){
                d.unite(x,last);
            }
            last = x;
        }
    }
    for (int i=1; i<=n; i++){
        cout << d.sz[d.find(i)] << " ";
    }
    cout << endl;

}

int main(){
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}