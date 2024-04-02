#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAX = 600;
pair<ll,ll> p[MAX];
int n, a, b;
struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = 1e9) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};


bool eval(ld x){
    dinitz d(a+b+10);
    for (int i=0; i<a; i++){
        d.add(0,i+1,1);
    }

    for (int j=a; j<a+b; j++){
        d.add(j+1, a+b+1, 1);
    }

    for (int i=0; i<a; i++){
        for (int j=a; j<a+b; j++){
            if ( (p[i].first - p[j].first)*(p[i].first - p[j].first) +  (p[i].second - p[j].second)*(p[i].second - p[j].second) < x){
                d.add(i+1, j+1, 1);
            } 
        }
    }
    return a+b-d.max_flow(0, a+b+1) >= n;

}


int main(){
    cin >> n >> a >> b;
    int i =0;
    for (; i<a; i++){
        cin >> p[i].first >> p[i].second;
    }
    for (;i<a+b; i++){
        cin >> p[i].first >> p[i].second;
    }
    ld l = 0;
    ld r = 1e9;
    ld m;
    int cont = 300;
    while (cont--){
        m = l + (r-l)/2;
        
        if (eval(m)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(15) << sqrt(l) << endl;

}