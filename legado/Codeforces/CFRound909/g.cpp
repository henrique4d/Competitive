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
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 1e5+10;
vector<ll> arvore;

pair<ll,ll> tour[MAXN];

set<ll> st[4*MAXN];

void build(int v, int tl, int tr){
    st[v].clear();
    if (tl == tr){
        st[v].insert(arvore[tl]);
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    for (auto x:st[2*v]) st[v].insert(x);
    for (auto x:st[2*v+1]) st[v].insert(x);   
}

bool query(int v, int tl, int tr, int l, int r, int xl, int xr){
    if (l > r) return false;
    if (l == tl and r == tr){
        auto it = st[v].lower_bound(xl);
        if (it == st[v].end()) return false;
        return *it <= xr;
    }
    int tm = tl + (tr-tl)/2;
    return query(2*v, tl, tm, l, min(r, tm), xl, xr) or query(2*v+1, tm+1, tr, max(l, tm+1),r, xl, xr);
}


void dfs(int u, ll &cont, vector<ll> adj[], int p){
    tour[u].first = cont;
    arvore.push_back(u);
    for (auto v:adj[u]){
        if (v == p) continue;
        cont++;
        dfs(v, cont, adj, u);
    }
    tour[u].second = cont;
}

void solve(){
    int n,q;
    arvore.clear();
    cin >> n >> q;
    vector<pair<ll,ll>> tree(n-1);
    vector<ll> p(n+5);
    
    ll a,b;
    for (int i=0; i<n-1; i++){
        cin >> tree[i].first >> tree[i].second;
    }

    ll x;
    for (int i=0; i<n; i++){
        cin >> x;
        p[x] = i;
    }
    vector<ll> adj[n];
    for (int i=0; i<n-1; i++){
        adj [p[tree[i].first]].push_back(p[tree[i].second]);
        adj [p[tree[i].second]].push_back(p[tree[i].first]);

    }

    ll cont = 0;
    dfs(p[1],cont, adj, -1);

    ll l,r;

    build(1,0, n-1);
    while(q--){
        cin >> l >> r >> x;
        l--;
        r--;
        query(1,0,n-1,tour[p[x]].first,tour[p[x]].second,l,r)?yes():no();
    }
    cout << endl;

}

int main() {
    optimize; 
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}