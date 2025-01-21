#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

#define fi first 
#define se second 
#define pb push_back

#define all(x) x.begin(),x.end()
#define ms(x,a) memset(x,a,sizeof(x))

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

#define mod 998244353LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 1e3+10;
vector<ll> g[MAXN];
pair<int,int> cores[MAXN];
ll n;

void init(){
    for (int i=0; i<n+10; i++){
        cores[i] = {-1,-1};
        g[i].clear();
    }
}

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
	int dfs(int v, int s, int f = INF) {
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


void solve(){
    cin >> n;
    init();
    char c;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> c;
            if (c == '1' and i != j) {
                g[i].push_back(j);
            }
        }
    }

    queue<pair<ll,ll>> to_proces;
    int c1 = 0;
    int c2 = 0;

    for (int i=0; i<n; i++){
        if (cores[i] == make_pair(-1,-1)){
            cores[i].first = c1++;
            to_proces.push({i,0});
            if (g[i].size()){
                int j = g[i][0];
                cores[j].first = cores[i].first;
                to_proces.push({j,0});

                int u = 0;
                int v = 0;
                while (u < g[i].size() and v < g[j].size()){
                    if (g[i][u] == g[j][v]){        
                        cores[g[i][u]].first = cores[i].first;;
                        to_proces.push({g[i][u],0}); 
                        u++;
                        v++;
                    }
                    else if (g[i][u] < g[j][v]) u++;
                    else v++;
                }
            }

            while (!to_proces.empty()){
                int u = to_proces.front().first;
                int tipo = to_proces.front().second;
                to_proces.pop();
                
                if (cores[u].first != -1 and cores[u].second != -1) continue;

                if (tipo == 0){
                    for (auto v:g[u]){
                        if (cores[v].first != cores[u].first and cores[v].first != -1 and cores[v].second != -1){
                            cores[u].second = cores[v].second;
                            break;
                        }
                    }
                    if (cores[u].second == -1) cores[u].second = c2++;
                    
                    for (auto v:g[u]){                        
                        if (cores[v].first != cores[u].first and cores[v].second == -1){
                            cores[v].second = cores[u].second;
                            to_proces.push({v,1});
                        }
                    }

                }
                
                if (tipo == 1){
                    for (auto v:g[u]){
                        if (cores[v].second != cores[u].second and cores[v].second != -1 and cores[v].first != -1){
                            cores[u].first = cores[v].first;
                            break;
                        }
                    }
                    if (cores[u].first == -1) cores[u].first = c1++;
                    for (auto v:g[u]){
                        if (cores[v].second != cores[u].second and cores[v].first == -1){
                            cores[v].first = cores[u].first;
                            to_proces.push({v,0});
                        }
                    }
                }

            }
        }
    }

    dinitz flow(n+c1+c2+2);
    for (int i=1; i<=c1; i++){
        flow.add(0,i,1);
    }
    for (int i=0; i<n; i++){
        flow.add(cores[i].first+1, c1+1+i,1);
        flow.add(c1+1+i,c1+n+1 + cores[i].second,1);
    }
    for (int i=c1+n+1; i<c1+n+1+c2;i++){
        flow.add(i,n+c1+c2+1,1);
    }
    cout << flow.max_flow(0,n+c1+c2+1) << endl;    
}


int main() {
    optimize; 
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}