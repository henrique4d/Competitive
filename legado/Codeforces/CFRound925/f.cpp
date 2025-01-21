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

set<ll> adj[MAXN];
bool used[MAXN];
bool ciclo = false;
int n,m;

vector<ll> topological;

void dfs(int u){
    used[u] = true;
    for (auto v:adj[u]){
        if (used[v]) continue;
        dfs(v);
    }
    topological.push_back(u);
}

void init(){
    ciclo = false;
    for (int i=0; i<n+5; i++){
        used[i] = false;
        adj[i].clear();
    }
    topological.clear();
}


void solve(){
    
    cin >> n >> m;
    init();
    ll atual;
    ll last;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            last = atual;
            cin >> atual;
            if (j >= 2) adj[last].insert(atual);
        }
    }

    for (int i=1; i<=n; i++){
        if (!used[i]){
            dfs(i);
        }
    }
    
    for (int i=1; i<=n; i++){
        used[i] = false;
    }    
    for (auto it = topological.rbegin(); it!=topological.rend(); it++){
        used[*it] = true;
        for (auto v:adj[*it]){
            if (used[v]){
                no();
                return;
            }
        }
    }

    yes();
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