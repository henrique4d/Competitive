#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef int ll;
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

const ll MAX = 5e4+10;
vector<pair<ll,ll>> adj[MAX];
bool visited[MAX];
ll n,m,q,u,v,w,p;


namespace sparseTable{
    ll st[25][MAX];

    void build(ll n, ll *v){
        for (ll i=0; i<n; i++){
            st[0][i] = v[i];
        }

        for (ll k=1; k<25; k++){
            for (ll i=0; i + (1<<k) <=n; i++){
                st[k][i] = min( st[k-1][i], st[k-1][i + (1<<(k-1))]);
            }
        }
    }

    ll query(ll l, ll r) {
		ll i = __builtin_clz(1) - __builtin_clz(r-l+1);
    	return min(st[i][l], st[i][r-(1<<i)+1]);
	}
}


namespace hld{
    vector<pair<ll,ll>> g[MAX];

    ll pos[MAX], sz[MAX];
    ll sobe[MAX], pai[MAX];
    ll h[MAX], v[MAX], t;

    void build_hld(ll k, ll p = -1, ll f = 1){
        v[pos[k] = t++] = sobe[k]; sz[k] = 1;
        for (auto & i: g[k]) if (i.first != p){
            auto [u,w] = i;
            sobe[u] = w; pai[u] = k;
            h[u] = (i == g[k][0] ? h[k] : u);
            build_hld(u,k,f); sz[k] += sz[u];
            if (sz[u] > sz[g[k][0].first] or g[k][0].first == p){
                swap(i, g[k][0]);
            }
            if(p*f == -1) build_hld(h[k] = k, -1, t = 0);
        }
    }

    void build(ll root = 0){
        t = 0;
        build_hld(root);
        sparseTable::build(t, v);
    }

    ll query_path(ll a, ll b){
        if (a == b) return INF;
        if (pos[a] < pos[b]) swap(a,b);

        if (h[a] == h[b]) return sparseTable::query(pos[b]+1, pos[a]);
        return min(sparseTable::query(pos[h[a]], pos[a]),query_path(pai[h[a]], b));
    }

}

void solve(){
    cin >> n >> m >> q;
    for (ll i=0; i<m; i++){
        cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    priority_queue<pair<ll,pair<ll,ll>>> pq;
    pq.push({INFLL,{0,-1}});
    
    while (!pq.empty()){
        w = pq.top().first;
        u = pq.top().second.first;
        p = pq.top().second.second;

        pq.pop();

        if (visited[u]) continue;    
        if (p != -1){
            visited[u] = true;
            visited[p] = true;
            hld::g[p].push_back({u,w});
        }

        for (auto [v,w]:adj[u]){
            if (visited[v]) continue;
            pq.push({w,{v,u}});
        }
    }

    hld::build();

    while(q--){
        cin >> u >> v;
        u--,v--;
        cout << hld::query_path(u,v) << endl;
    }
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