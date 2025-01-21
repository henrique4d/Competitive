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


const ll MAXN = 3e5+60;
vector<ll> adj[MAXN];
ll dp[MAXN][3];
int n;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll p){
    return binpow(a, p-2, p);
}


void calcdp0(int u, int p){
    dp[u][0] = 1;
    // cout << "chamando dp para " << u << " " << p << endl;
    for (auto v:adj[u]){
        if (v == p) continue;
        calcdp0(v,u);
        dp[u][0]*=dp[v][0];
        dp[u][0]%=mod;
    }
}

void calcdp1(int u, int p){
    dp[u][1] = 1;
    for (auto v:adj[u]){
        if (v == p) continue;
        calcdp1(v,u);
        dp[u][1]*= ((dp[v][0] + dp[v][1])%mod);
        dp[u][1]%=mod;
    }
}

void calcdp2(int u, int p){
    dp[u][2] = 0;
    
    for (auto v:adj[u]){
        if (v == p) continue;
        calcdp2(v,u);

        dp[u][2] +=  (( (dp[u][0] * inv(dp[v][0], mod))%mod) * dp[v][2])%mod;
        dp[u][2] %= mod;


        dp[u][2] +=  (( (dp[u][0] * inv(dp[v][0], mod))%mod) * dp[v][1])%mod;
        dp[u][2] %= mod;

    }

}

void init(){
    for (int i=0; i<n +10; i++){
        adj[i].clear();
    }
}

void solve(){
    cin >> n;
    init();
    ll a,b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // for (int i=0; i<n; i++){
    //     cout << i << " : " << adj[i] << endl;
    // }
    calcdp0(0,-1);
    calcdp1(0,-1);
    calcdp2(0,-1);
    ll resp = (((dp[0][0] + dp[0][1])%mod) + dp[0][2]) %mod;  
    cout << resp << endl;
    // for (int i=0; i<n; i++){
    //     cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;

    // }
    
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