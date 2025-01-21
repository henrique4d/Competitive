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
vector<ll> g[MAXN];
ll n,q;

struct centroid {
    vector<bool> vis;
    vector<int> parent;
    vector<int> sz;
    int n;

    void init(int s){
        n = s;
        vis = vector<bool>(n,0);
        parent = vector<int>(n);
        sz = vector<int>(n);
    }

    int find_size(int u, int p = -1){
        if (vis[u]) return 0;
        sz[u] = 1;

        for (auto v:g[u]) if(v!= p){
            sz[u] += find_size(v, u);
        }
        return sz[u];
    }

    int find_centroid(int u, int p, int n){
        for (auto v:g[u]) if (v!= p){
            if (!vis[v] and sz[v] > n/2){
                return find_centroid(v,u,n);
            }
        }
        return u;
    }

    void init_centroid(int u = 0, int p = -1){
        find_size(u);
        
        int c = find_centroid(u,-1,sz[u]);
        vis[c] = true;
        parent[c] = p;
        
        for (auto v:g[c]){
            if (!vis[v]) init_centroid(v,c);
        }
    }
};

struct BinaryLifting{
    int p;
    int pai[25][MAXN];
    int in[MAXN], out[MAXN];
    int deep[MAXN];

    void dfs(int k, int d = 0){
        in[k] = p++;
        deep[k] = d;
        for (int i=0; i<(int)g[k].size(); i++){
            if (in[g[k][i]] == -1){
                pai[0][g[k][i]] = k;
                dfs(g[k][i], d+1);
            }
        }
        out[k] = p++;
    }

    void build(int raiz){
        for (int i=0; i<n;i++) pai[0][i] = i;
        p = 0;
        memset(in,-1, sizeof in);
        dfs(raiz);
        for (int k =1; k < 25; k++) for (int i=0; i<n; i++){
            pai[k][i] = pai[k-1][pai[k-1][i]];
        }
    }

    bool anc(int a, int b){
        return in[a] <= in[b] and out[a] >= out[b];
    }

    int lca(int a, int b){
        if(anc(a,b)) return a;
        if (anc(b,a)) return b;
        for (int k = 25-1; k>=0; k--){
            if (!anc(pai[k][a], b)) a = pai[k][a];
        }
        return pai[0][a];
    }

    int dist(int a, int b){
        return deep[a] + deep[b] - 2*deep[lca(a,b)];
    }
};
centroid Cent;
BinaryLifting lift;

pair<int,int> best[MAXN];

void update(int u){
    best[u] = {0,u};
    int v = u;
    while (Cent.parent[v] != -1){
        v = Cent.parent[v];
        best[v] = min(best[v], make_pair(lift.dist(u,v), u));

    }
}

int query(int u){
    pair<int,int> resp = best[u];
    int v = u;
    while (Cent.parent[v] !=-1){
        v = Cent.parent[v];    
        resp = min(resp, make_pair(lift.dist(u,v) + best[v].first, best[v].second));
    }

    return resp.second;
}


void init(){
    for (int i=0; i<n+10; i++){
        best[i] = {INF,i};
    }
}

void solve(){
    cin >> n;
    init();
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Cent.init(n);
    Cent.init_centroid();

    lift.build(0);

    vector<ll> resp;
    for (int i=n-1; i>=0; i--){
        resp.push_back(query(i));
        update(i);
    }
    reverse(all(resp));
    for (auto x:resp){
        cout << x+1 << " ";
    }
    cout << endl;
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