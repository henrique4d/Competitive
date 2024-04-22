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
#define MOD 998244353LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

const int MAXN = 2e4+10;
vector<pair<ll,ll>> g[MAXN];
bool visited[MAXN];
bool visited2[MAXN];


int n,m,a,b,c;
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
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--,b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    priority_queue<pair<ll,ll>> pq;
    pq.push({INFLL,0});

    ll neck = INFLL;
    while (!pq.empty()){
        auto [w,u] = pq.top();
        
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        neck = min(neck, w);

        for (auto [v,d]:g[u]) if(!visited[v]){
            pq.push({d,v});
        }
    }

    vector<pair<ll,pair<ll,ll>>> edge;
    vector<pair<ll,pair<ll,ll>>> tree;

    for (int u=0; u<n; u++){
        for (auto [v,w]:g[u]) if (w >= neck){
            edge.push_back({w,{u,v}});
        }
    }

    dsu ds(n);
    sort(all(edge));
    for (int i=0; i<edge.size(); i++){
        if (ds.find(edge[i].second.first) != ds.find(edge[i].second.second)){
            ds.unite(edge[i].second.first, edge[i].second.second);

            tree.push_back(edge[i]);
        }
    }

    dsu ds2(n);
    ll resp = 0;
    for (int i=tree.size()-1; i>=0; i--){
        resp += tree[i].first * ds2.sz[ds2.find(tree[i].second.first)] * ds2.sz[ds2.find(tree[i].second.second)];    
        ds2.unite(tree[i].second.first, tree[i].second.second);
    }

    cout << resp << endl;
}
 
int main() {
    optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}