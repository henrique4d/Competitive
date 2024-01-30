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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

const ll MAXN = 1e3+10;
ll a[MAXN];

vector<pair<ll,int>> adj[MAXN];
ll component[MAXN];

void dfs(int u, int c){
    if (component[u] and component[u] != c){
        cout << "Impossible\n";
        exit(0);
    }
    if (component[u]) return;
    component[u] = c;

    for (auto v:adj[u]){
        if (v.second){
            dfs(v.first, c);
        }
        else{
            dfs(v.first, -c);
        }
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    int a,b;
    bool c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--,b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    for (int i=0; i<n; i++){
        if (!component[i]){
            dfs(i, 1);
        }
    }
    
    vector<ll> resp;
    for (int i=0; i<n; i++){
        if (component[i] == 1) resp.push_back(i);
    }
    cout << resp.size() << endl;
    for (int i=0; i<resp.size(); i++){
        cout << resp[i]+1 << " ";
    }
    cout << endl;
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