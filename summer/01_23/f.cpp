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
const ll MAXN = 1e4+10;
vector<ll> g[MAXN];
vector<ll> rev[MAXN];
bool visited[MAXN];
bool sink[MAXN];
ll comp[MAXN];
ll n,m,a,b;
vector<ll> top_sort;

void init(){
    for (int i=0; i<n+10; i++){
        g[i].clear();
        visited[i] =false;
        sink[i] = true;
        comp[i] = 0;
        rev[i].clear();
    }
    top_sort.clear();
}

void dfs(int u){
    visited[u] = true;
    for (auto v:g[u]) if (!visited[v]){
        dfs(v);
    }
    top_sort.push_back(u);
}

void dfs2(int u, int c){
    comp[u] = c;
    for (auto v:rev[u]) if (!comp[v]){
        dfs2(v,c);
    }
}


void solve(){
    if (n == 0) return;
    cin >> m;
    init();
    for (int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        rev[b].push_back(a);
    }

    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    reverse(all(top_sort));

    int c = 1;
    for (auto u:top_sort){
        if (!comp[u]) dfs2(u,c++);
    }

    for (int u=1; u<=n; u++){
        for (auto v:g[u]){
            if (comp[u] != comp[v]){
                sink[comp[u]] = false;
            }
        }
    }


    for (int i=1; i<=n; i++){
        if (sink[comp[i]]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    optimize; 
    ll T = 1;
    // cin >> T;
    while(cin >> n) {
        solve();
    }
    return 0;
}