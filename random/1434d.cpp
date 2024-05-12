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
const int MAXN = 1e6+10;
vector<int> g[MAXN];
pair<int,int> edge[MAXN];
pair<int,int> euler[MAXN];
vector<int> tour;
int resp[MAXN];
int dist[MAXN];
int maior_dist = 0;
int mais_dist = 0;
int n,q;
int t;
int a,b,c;


pair<int,int> st[4*MAXN];
int lazy[4*MAXN];

pair<int,int> combine(pair<int,int> a, pair<int,int>b){
    return {max(a.first, b.first), max(a.second, b.second)};
}

void prop(int v){
    if (lazy[v]&1){
        swap(st[2*v].first, st[2*v].second);
        swap(st[2*v+1].first, st[2*v+1].second);
    }
    lazy[2*v] += lazy[v]%2;
    lazy[2*v+1] += lazy[v]%2;
    lazy[v] = 0;
}


void build(int v, int tl, int tr){
    lazy[v] = 0;
    if (tl == tr){
        st[v] = {tour[tl], 0};
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = combine(st[2*v], st[2*v+1]);
}

void update(int v, int tl, int tr, int l, int r){
    if (l > r) return;
    if (tl == l and tr == r){
        swap(st[v].first, st[v].second);
        lazy[v]++;
        return;
    }
    prop(v);
    int tm = tl + (tr - tl)/2;
    update(2*v, tl, tm, l, min(tm,r));
    update(2*v+1, tm+1, tr, max(tm+1, l), r);
    st[v] = combine(st[2*v], st[2*v+1]);
}

pair<int,int> query(int v, int tl, int tr, int l, int r){
    if (l > r) return {-INF, -INF};
    if (tl == l and tr == r){
        return st[v];
    }
    prop(v);
    int tm = tl + (tr-tl)/2;

    return combine( query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(tm+1,l), r));
}





void init(){
    maior_dist = 0;
    mais_dist = 0;
    t = 0;
    tour.clear();
}

void dfs(int u, int p, int d){
    euler[u].first = t;
    dist[u] = d;
    tour.push_back(dist[u]);
    if (dist[u] > maior_dist){
        maior_dist = dist[u];
        mais_dist = u;
    }
    for (auto v:g[u]) if (v!=p){
        t++;
        dfs(v,u,d+1);
    }
    euler[u].second = t;
}


void solve(){
    cin >> n;
    vector<pair<int,bool>> quer;

    for (int i=1; i<n; i++){
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = {a,b};

        if (c){
            quer.push_back({i,false});
        }
    }
    cin >> q;
    while(q--){
        cin >> a;
        quer.push_back({a,true});
    }

    init();
    dfs(1,0,0);
    int d1 = mais_dist;

    init();
    dfs(d1,0,0);
   
    build(1,0,n-1);

    for (int i=0; i<quer.size(); i++){
        auto [ed, print] = quer[i];    
        int u = edge[ed].first;
        int v = edge[ed].second;
        if (euler[u].first < euler[v].first){
            update(1,0,n-1, euler[v].first, euler[v].second);
        }
        else{
            update(1,0,n-1, euler[u].first, euler[u].second);
        }

        resp[i] = max(resp[i], query(1,0,n-1, euler[d1].first, euler[d1].second).first);
    }


    int d2 = mais_dist;

    init();
    dfs(d2,0,0);


    build(1,0,n-1);
    
    for (int i=0; i<quer.size(); i++){
        auto [ed, print] = quer[i];
        
        int u = edge[ed].first;
        int v = edge[ed].second;
        if (euler[u].first < euler[v].first){
            update(1,0,n-1, euler[v].first, euler[v].second);
        }
        else{
            update(1,0,n-1, euler[u].first, euler[u].second);
        }

        resp[i] = max(resp[i], query(1,0,n-1, euler[d2].first, euler[d2].second).first);
    }

    for (int i=0; i<quer.size(); i++){
        auto [ed, print] = quer[i];
        if (print) cout << resp[i] << endl;
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