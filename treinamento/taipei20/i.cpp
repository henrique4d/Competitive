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
const int MAXN = 2e3+10;
int n,m,a,b;
vector<pair<int,int>> g[MAXN];
int pre[MAXN];
int low[MAXN];
int bridge;
int articulation;
int components;
int bigComponent;
stack<int> edg;
int t = 0;


void init(){   
    for (int i=0; i<n+10; i++){
        g[i].clear();
        pre[i] = 0;
        low[i] = 0;
    }
    bridge = 0;
    articulation = 0;
    components = 0;
    bigComponent = 0;
    while(!edg.empty()){
        edg.pop();
    }
    t = 1;
}


void computeComponent(int id){
    int atual;
    int sz = 0;
    do{
        atual = edg.top();
        edg.pop();
        sz++;
        if (edg.empty()) break;
    }while(atual!=id);

    //if (sz >= 3){
        components++;
        bigComponent = max(bigComponent, sz);
    //}
    
}

void dfs(int u, int p){
    pre[u] = t++;
    low[u] = pre[u];
    int sz = 0;

    bool artc = false;
        
    for (auto [v,e]:g[u]) if (v!=p){

        if (pre[v] > pre[u]) continue; 
        edg.push(e); 
        if (!pre[v]){
            sz++;
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            
            bool novaComponente = false;
            if (u != 0 and low[v] >= pre[u]) novaComponente = true,artc = true;
            if (u == 0 and sz >=2) novaComponente = true, artc = true;

            if (novaComponente){
                computeComponent(e);
                //achar nova componente
            }
        }
        else{
            low[u] = min(low[u], pre[v]);
        }
    }
    if (artc)articulation++;

    if (u != 0 and low[u] == pre[u]){
        bridge++;
    }


}

void solve(){
    cin >> n >> m;
    init();
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    dfs(0,-1);
    computeComponent(-1);
    int gc = __gcd(components, bigComponent);
    cout << articulation << " " << bridge << " " << components/gc << " " << bigComponent/gc << endl;
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