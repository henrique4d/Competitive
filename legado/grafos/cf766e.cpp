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
const ll MAXN = 1e5+10;
vector<int> g[MAXN];
bool vis[MAXN];
int sz[MAXN];
int a[MAXN];
int n;

ll resp = 0;
pair<int,int> dfs(int u, int p, int j){
    int sum0 = 0;
    int sum1 = 0;

    for (auto v:g[u]) if (v!=p and !vis[v]){
        auto [s0, s1] = dfs(v, u, j);
        sum0 += s0;
        sum1 += s1;
    }
    if (a[u]&(1LL<<j)){
        swap(sum0,sum1);
        sum1++;
    }
    else{
        sum0++;
    }

    return {sum0, sum1};
}

int find_size(int u, int p = -1){
    if (vis[u]) return 0;
    sz[u] = 1;
    for (auto v:g[u]) if (v!=p){
        sz[u] += find_size(v,u);
    }
    return sz[u];
}

int find_centroid(int u, int p, int n){
    for (auto v:g[u]) if (v!=p){
        if (!vis[v] and sz[v] > n/2){
            return find_centroid(v,u,n);
        }
    }
    return u;
}

void init_centroid(int u = 0, int p =-1){
    find_size(u);

    int c= find_centroid(u,-1,sz[u]);
    vis[c] = true;

    for (int j=0; j<25;j++){
        int sum0 = 0;
        int sum1 = 0;
        for (auto v:g[c]) if (!vis[v] and v!=p){
            auto [s0, s1] = dfs(v, c,j);        
            if (a[c]&(1LL<<j)){
                resp += s0*sum0*(1LL<<j);
                resp += s1*sum1*(1LL<<j);
            }
            else{
                resp += s0*sum1*(1LL<<j);
                resp += s1*sum0*(1LL<<j);
            }
            sum0 += s0;
            sum1 += s1;
        }
        if (a[c]&(1LL<<j)) resp += (sum0+1)*(1LL<<j);
        else resp += sum1*(1LL<<j);
    }
    
    for (auto v:g[c]){
        if (!vis[v]){
            init_centroid(v,c);
        }
    }
}


void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init_centroid(0);

    cout << resp << endl;
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