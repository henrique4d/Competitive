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

const int MAXN = 1e6+10;
vector<int> g[MAXN];
vector<int> rev[MAXN];
bool visited[MAXN];
vector<int> top_sort;
int comp[MAXN];

int n,m,a,b;
void init(){
    top_sort.clear();
    for (int i=0; i<n+10; i++){
        g[i].clear();
        rev[i].clear();
        visited[i] = 0;
        comp[i] = 0;
    }
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
    for (auto v:rev[u]) if (!comp[v]) dfs2(v,c);
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        rev[b].push_back(a);
    }
    for (int i=0; i<n; i++){
        if (!visited[i]) dfs(i);
    }
    reverse(all(top_sort));
    
    int c = 1;
    for (auto u:top_sort){
        if (!comp[u]) dfs2(u,c++);
    }

    if (c == 2){
        no();
        return;
    }
    vector<int> jury;
    vector<int> cat;
    for (int i=0; i<n; i++){
        if (comp[i] == c-1) jury.push_back(i);
        else cat.push_back(i);
    }
    yes();
    cout << jury.size() << " " << cat.size() << endl;

    for (auto x:jury) cout << x+1 << " ";
    cout << endl;
    for (auto x:cat) cout << x+1 << " ";
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