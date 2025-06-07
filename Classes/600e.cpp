#include <bits/stdc++.h>
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
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5+10;
vector<ll> g[MAXN];
ll color[MAXN];
ll sz[MAXN];
ll cnt[MAXN];
pair<ll,ll> ans[MAXN];
vector<int> vec[MAXN];
ll n;

void dfs_size(int u, int p){
    sz[u] = 1;
    for (auto v:g[u]) if (v !=p){
        dfs_size(v,u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p, bool keep){
    int tam = -1, bigChild = -1;
    for (auto v:g[u]) if (v!=p){
        if (sz[v] > tam){
            tam = sz[v];
            bigChild = v;
        }
    }
    for (auto v:g[u]) if (v!= p and v!= bigChild){
        dfs(v, u, false);
    }
    if (bigChild != -1){
        dfs(bigChild, u, true);
        swap(vec[u], vec[bigChild]);
        ans[u] = ans[bigChild];
    }

    vec[u].push_back(u);
    cnt[color[u]]++;
    
    if (cnt[color[u]] == ans[u].first){
        ans[u].second += color[u];
    }
    if (cnt[color[u]] == ans[u].first + 1){
        ans[u].first = ans[u].first + 1;
        ans[u].second = color[u];
    }
    for (auto v:g[u]) if (v!= p and v!= bigChild){
        for (auto x:vec[v]){
            cnt[color[x]]++;
            vec[u].push_back(x);
            if (cnt[color[x]] == ans[u].first){
                ans[u].second += color[x];
            }
            if (cnt[color[x]] == ans[u].first + 1){
                ans[u].first = ans[u].first + 1;
                ans[u].second = color[x];
            }
        }
    }
    if (!keep){
        for (auto x:vec[u]){
            cnt[color[x]]--;
        }
    }
}

void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> color[i];
    }
    ll u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs_size(0,-1);
    dfs(0,-1, true);
    for (int i=0; i<n; i++){
        cout << ans[i].second << " ";
    }
    cout << endl;
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