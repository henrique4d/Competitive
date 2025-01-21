#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef unsigned long long ll;
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

const ll MAXN = 3e5+10;

ll dp[5][MAXN];
ll dano[MAXN];
vector<ll> g[MAXN];
ll degree[MAXN];
ll n;
// 0-> tem que pegar
// 1-> tem que pular ele e pegar ele logo em seguida
// 2-> tem que pular ele, pular o proximo e pegar ele só depois
// 3-> ele é o segundo a ser pulado e vai ser pego logo em seguida
// 4-> ele é o segundo a ser pulado e vai ser pego somente por ultimo

ll DP(int u, int estado, int p){
    if (dp[estado][u] != -1) return dp[estado][u];

    if (estado == 0){   // tem que pegar aquele vértice
        ll resp = dano[u];
        for (auto v:g[u]) if (v!=p){
            resp += min(DP(v,1,u),DP(v,2,u));
        }
        return dp[estado][u] = resp;
    }
    if (estado == 1){
        ll resp = 2*dano[u];
        for (auto v:g[u]) if (v!=p){
            resp += min(DP(v,4,u), DP(v,0,u));
        }
        return dp[estado][u] = resp;
    }
    if (estado == 2){
        ll resp = 3*dano[u];
        for (auto v:g[u]) if (v!=p){
            resp += min(DP(v,3,u), DP(v,0,u));
        }
        return dp[estado][u] = resp;
    }
    if (estado == 3){
        ll resp = 2*dano[u];
        for (auto v:g[u]) if (v!=p){
            resp += min(DP(v,0,u), DP(v,2,u));
        }
        return dp[estado][u] = resp;
    }
    if (estado == 4){
        ll resp = 3*dano[u];
        for (auto v:g[u]) if (v!=p){
            resp += min(DP(v,0,u), DP(v,1,u));
        }
        return dp[estado][u] = resp;
    }
}
void init(){
    for (int i=0; i<n+10; i++){
        g[i].clear();
        degree[i] = 0;
        for (int j=0; j<5; j++){
            dp[j][i] = -1;
        }
    }
}

void solve(){
    cin >> n;
    init();
    for (int i=0; i<n; i++){
        cin >> dano[i];
    } 
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        degree[u]++;
        degree[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=0; i<n; i++){
        if (degree[i] == 1 or degree[i] == 0){
            cout << min({DP(i,0,-1), DP(i,1,-1), DP(i,2,-1), DP(i,3,-1), DP(i,4,-1)}) << endl;
            return;
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