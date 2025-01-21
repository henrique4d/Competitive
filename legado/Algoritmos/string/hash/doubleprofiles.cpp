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
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 1e6 + 10;
vector<int> adj[MAXN];
map<pair<ll,ll>,ll> hashs;

ll compute_hash1(int pos){
    const int p = 101839;
    const int m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    for (int i=0; i<adj[pos].size(); i++){
        hash_value = (hash_value + adj[pos][i]*p_pow)%m;
        p_pow = p_pow*p %m;
    }
    return hash_value;
}

ll compute_hash2(int pos){
    const int p = 101737;
    const int m = 1e9 + 7;
    ll hash_value = 0;
    ll p_pow = 1;
    for (int i=0; i<adj[pos].size(); i++){
        hash_value = (hash_value + adj[pos][i]*p_pow)%m;
        p_pow = p_pow*p %m;
    }
    return hash_value;
}

void solve(){
    int n,m;
    cin >> n >> m;
    int u,v;
    for (int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1; i<=n; i++){
        sort(all(adj[i]));        
        hashs[{compute_hash1(i), compute_hash2(i)}]++;
        adj[i].push_back(i);
        sort(all(adj[i]));
        hashs[{compute_hash1(i), compute_hash2(i)}]++;
    }
    ll resp = 0;
    for (auto it:hashs){
        resp += (it.second * (it.second-1))/2;
    }
    cout << resp << endl;
}


int main() {
    optimize;
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}