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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
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
const ll MAXN = 3e5 + 10;
ll a[MAXN];
vector<ll> adj[MAXN];
pair<ll,ll> tour[MAXN];
stack<ll> lastApp[MAXN];
vector<ll> sameColor[MAXN];

ll st[4*MAXN];
ll lazy[4*MAXN];

void push(ll v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];

    st[2*v] += lazy[v];
    st[2*v+1] += lazy[v];

    lazy[v] = 0;
}

void build(ll v, ll tl, ll tr){
    st[v] = 0;
    lazy[v] = 0;
    if (tl == tr){
        st[v] = 0;
        lazy[v] = 0;
        return;
    }
    ll tm = tl+(tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = max(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if (l > r) return;
    if (l == tl and r == tr){
        st[v] += x;
        lazy[v] += x;
        return;
    }
    push(v);
    ll tm = tl+(tr-tl)/2;
    update(2*v, tl, tm, l, min(tm, r), x);
    update(2*v+1, tm+1, tr, max(tm+1,l),r, x);
    st[v] = max(st[2*v], st[2*v+1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return -1;
    if (l == tl and r == tr){
        return st[v];
    }
    push(v);
    ll tm = tl + (tr-tl)/2;
    return max(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(tm+1, l),r));
}



void dfs(int u, int &cont){
    tour[u].first = cont;
    if (!lastApp[a[u]].empty()){
        sameColor[lastApp[a[u]].top()].push_back(u);
    }
    lastApp[a[u]].push(u);
    for (auto v:adj[u]){
        cont++;
        dfs(v, cont);
    }
    tour[u].second = cont;
    lastApp[a[u]].pop();
}

ll resp;
int n;
    

void dfs2(ll u){
    for (auto v:adj[u]){
        dfs2(v);
    }
    update(1,0,n-1,tour[u].first, tour[u].second, 1);
    for (auto v:sameColor[u]){
        update(1,0,n-1,tour[v].first, tour[v].second, -1);
    }
    ll maior = 1;
    ll secmaior = 1;
    ll val;
    for (auto v:adj[u]){
        val = query(1,0,n-1,tour[v].first, tour[v].second);
        if (val > maior) swap(val, maior);
        if(val > secmaior) swap(val, secmaior);
    }
    resp = max(resp, maior*secmaior);
}

void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        adj[i].clear();
        lastApp[i] = stack<ll>();
        sameColor[i].clear();
    }
    int pai;
    for (int i=1; i<n; i++){
        cin >> pai;
        pai--;
        adj[pai].push_back(i);
    }
    for (int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }
    int cont = 0;
    dfs(0, cont);
    build(1,0,n-1);
    resp = 0;
    dfs2(0);
    cout << resp << endl;
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