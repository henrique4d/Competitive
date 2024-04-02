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
#define MOD 998244353
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

const ll MAXN = 2e5+10;
vector<pair<ll,ll>> adj[MAXN];
ll low[MAXN];
ll pre[MAXN];
bool visited[MAXN];
bool visited2[MAXN];
ll cont = 1;

pair<ll,ll> lighter;
ll lighterValue;

void dfs(ll u, ll p, ll cost){
    low[u] = cont;
    pre[u] = cont;
    visited[u] = true;
    cont++;
    for (auto [v,w]:adj[u]){        
        if (visited[v]){
            if (v == p) continue;
            if (w < lighterValue){
                lighterValue = w;
                lighter = {u,v};
            }
            low[u] = min(low[u], pre[v]);
        }
        if (!visited[v]){
            dfs(v, u, w);
            low[u] = min(low[u], low[v]);
        }
    }
    
    if (u != 0 and low[u] < pre[u]){
        // cout << "vertice " << u << " " << p << " " << cost << endl;
        if (cost < lighterValue){
            lighterValue = cost;
            lighter = {u,p};
        }
    }
}

vector<ll> resp;
bool dfs2(ll u, ll p, ll obj){
    visited2[u] = true;

    for (auto[v,w]:adj[u]){
        if (v == p or visited2[v]) continue;
        
        if (v == obj){
            resp.push_back(obj);
            return true;
        }
        if (dfs2(v, u, obj)){
            resp.push_back(v);
            return true;
        }
    }

    return false;
}
ll n, m;
    
void init(){
    for (int i=0; i<n+5; i++){
        adj[i].clear();
        visited[i] = false;
        visited2[i] = false;
        pre[i] = 0;
        low[i] = 0;
    }
    resp.clear();
    lighterValue = INFLL;
    cont = 1;

}

void solve(){
    cin >> n >> m;
    
    init();
    ll u,v,c;
    for (int i=0; i<m; i++){
        cin >> u >> v >> c;
        u--;
        v--;
        
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    for (int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,-1,INFLL);
        }
    }
   
    dfs2(lighter.first, lighter.second, lighter.second);
   
    resp.push_back(lighter.first);
    cout << lighterValue << " " << resp.size() << endl;
    for (int i=0; i<resp.size(); i++){
        cout << resp[i]+1 << " ";
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