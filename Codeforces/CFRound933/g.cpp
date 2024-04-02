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
const ll MAXN = 4e5+10;
set<ll> adj[MAXN];
bool visited[MAXN];
ll n,m;
ll ini, fim;

void init(){
    for (int i=0; i<n+m+5; i++){
        adj[i].clear();
        visited[i] = false;
    }
}

struct elem{
    ll u,v,c;
};

void solve(){
    cin >> n >> m;
    vector<elem> a(m);
    init();
    int u,v,c;
    
    vector<int> vals;
    for (int i=0; i<m; i++){
        cin >> a[i].u >> a[i].v >> a[i].c;
        vals.push_back(a[i].c);
    }
    sort(all(vals));

    vals.resize(unique(all(vals)) - vals.begin());
 
    for (int i=0; i<m; i++){
        u = a[i].u;
        v = a[i].v;
        c = (lower_bound(all(vals), a[i].c) - vals.begin()) + 1;

        adj[u].insert(n + c);
        adj[n+c].insert(u);

        adj[v].insert(n + c);
        adj[n+c].insert(v);
    }
    cin >> ini >> fim;
    if (ini == fim){
        cout << 0 << endl;
        return;
    }
 
    queue<pair<ll,ll>> q;
    q.push({ini, 0});

    while (true){
        auto [u,w] = q.front();
        q.pop();
        for (auto v:adj[u]){
            if (v == fim){
                cout << (w+1)/2 << endl;
                return;
            }
            if (!visited[v]){
                visited[v] = true;
                q.push({v, w+1});
            }
        }
    }
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