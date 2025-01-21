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
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5+10;
pair<ll,ll> edge[MAXN];
pair<ll,ll> edgeVertices[MAXN];

pair<ll,ll> euler[MAXN];
pair<ll,ll> tour[MAXN];
vector<pair<ll,ll>> g[MAXN];
ll edgeToTour[MAXN];
ll forca[MAXN];

ll n, t=0;

pair<ll,ll> st[4*MAXN];

void build(ll v, ll tl, ll tr){
    if (tl == tr){
        st[v] = euler[tl];
        return;
    }
    ll tm = tl+(tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = max(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll pos, ll x){
    if (tl == tr){
        st[v].first = x;
        return;
    }
    ll tm = tl+(tr-tl)/2;
    if ( pos <= tm) update(2*v, tl, tm, pos, x);
    else update(2*v+1, tm+1, tr, pos, x);
    st[v] = max(st[2*v], st[2*v+1]);
}

pair<ll,ll> query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return {-INFLL, -INFLL};
    if (l == tl and r == tr){
        return st[v];
    }
    ll tm = tl + (tr-tl)/2;
    
    return (max(query(2*v,tl, tm, l, min(r, tm)), query(2*v+1, tm+1, r, max(l,tm+1), r)) );
}

void dfs(ll u, ll p, ll h, ll f){
    tour[u].first = t;
    forca[u] = f;
    for (auto [v,e]:g[u]) if (v!=p){
        edgeToTour[e] = t;
        euler[t] = {h,e};
        t++;
        dfs(v,u,h+1, edge[e].second);
    }
    tour[u].second = t;
}

ll dfs2(ll u, ll p){
    ll soma = 0;

    for (auto [v,e]:g[u])if (v!=p) {
        soma += dfs2(v,u);
        soma += edge[e].first;
    }

    ll sobrando = soma - forca[u];
    while (sobrando > 0){
        auto [h,e] = query(1,0,n-1,tour[u].first, tour[u].second);
        if (h == -1){
            cout << -1 << endl;
            exit(0);
        }
        ll decay = min({edge[e].first-1, edge[e].second, sobrando});

        sobrando -= decay;
        edge[e].first -= decay;
        edge[e].second -= decay;
        soma -= decay;
        if (edge[e].first == 1 or edge[e].second == 0){
            update(1,0,n-1, edgeToTour[e],(ll)-1);
        }
    }
    return soma;
}



void solve(){
    cin >> n;
    n--;
    ll u,v,w,s;
    for (int i=0; i<n; i++){
        cin >> u >> v >> w >> s;
        edge[i] = {w,s};
        edgeVertices[i] = {u,v};
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs(1,0,0,INFLL);
    build(1,0,n-1);
    dfs2(1,0);
    cout << n+1 << endl;
    for (int i=0; i<n; i++){
        cout << edgeVertices[i].first << " " << edgeVertices[i].second << " " << edge[i].first << " " << edge[i].second << endl;
    }
}

int main() {
    optimize; 
    ll T = 1;
    // cin >> T;,
    while(T--) {
        solve();
    }
    return 0;
}