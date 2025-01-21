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
const ll MAXN = 1e5+10;
vector<pair<ll,ll>> g[MAXN];
pair<ll,ll> a[MAXN];
pair<ll,ll> pai[MAXN];
ll grau[MAXN];
ll ans[MAXN];
ll numFilhos[MAXN];
ll cont[MAXN];
ll paiGambiarra;

vector<pair<ll,ll>> queries[MAXN];
ll n,q;

bool compare(pair<int,int> primeiro, pair<int,int> segundo){
    int u = primeiro.first;
    int v = segundo.first;
    if (u == paiGambiarra) return false;
    if (v == paiGambiarra) return true;
    return make_pair(a[u].first + pai[u].second, a[u].second)  < make_pair(a[v].first + pai[v].second, a[v].second);
}

void dfs(int u, int p){
    for (auto [v,e]:g[u]) if (v!=p){
        dfs(v,u);
        pai[v] = {u,e};
        numFilhos[u]++;
    }
    for (auto [v,e]:g[u]) if (v!=p){
        a[u] = min(a[u], {a[v].first + e, a[v].second});
    }
    if (a[u] == make_pair((ll)INF, (ll)INF) ) a[u] = {0,u};
    paiGambiarra = pai[u].first;
    sort(g[u].begin(), g[u].end(), compare);
    cont[a[u].second]++;
}

void dfs2(int u, int p){
    for (auto [pos, q]:queries[u]){
        ans[q] = cont[pos];
    }
    for (auto [v,e]:g[u]) if (v!= p){
        pair<ll,ll> valOriginalU = a[u];
        pair<ll,ll> valOriginalV = a[v];
        cont[a[u].second]--;
        cont[a[v].second]--;
        if (a[u].second == a[v].second){
            a[u] = {INF,INF};
            if (pai[u].first != -1) a[u] = {a[pai[u].first].first + pai[u].second, a[pai[u].first].second};            
            if (g[u].size() >= 2 and numFilhos[u] >= 2){
                if (v == g[u][0].first) a[u] = min(a[u], { a[g[u][1].first].first + g[u][1].second, a[g[u][1].first].second });
                else a[u] = min(a[u], { a[g[u][0].first].first + g[u][0].second, a[g[u][0].first].second });
            }
        }
        a[v] = min(a[v], {a[u].first + e, a[u].second});
        cont[a[u].second]++;
        cont[a[v].second]++;
        dfs2(v, u);
        cont[a[u].second]--;
        cont[a[v].second]--;
        a[u] = valOriginalU;
        a[v] = valOriginalV;
        cont[a[u].second]++;
        cont[a[v].second]++;
    }
}

void init(){
    for (int i=0; i<n+10; i++){
        a[i] = {INF, INF};
        pai[i] = {-1,INF};
    }
}

void solve(){
    cin >> n;
    init();
    bool always2 = n == 2;
    ll u,v,w;
    for (int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> q;
    for (int i=0; i<q; i++){
        ll comeco, fim;
        cin >> comeco >> fim;
        comeco--,fim--;
     
        queries[fim].push_back({comeco, i});
    }
    for (int i=0; i<n; i++){
        if (g[i].size() != 1){
            dfs(i, -1);
            dfs2(i,-1);
            break;
        }
    }
    for (int i=0; i<q; i++){
        if (always2) cout << 1 << endl;
        else cout << ans[i] << endl;
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