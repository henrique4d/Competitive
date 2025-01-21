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
const int MAXN = 6000;
vector<ll> g[MAXN];
int dp[MAXN][MAXN];
ll a[MAXN];
ll soma[MAXN];
ll n;
ll resp = 0;

void dfs(int u, int p){
    int contfilhos = 0;
    for (auto v:g[u]) if (v!=p){
        dfs(v,u);
        soma[u] += a[v];
        contfilhos++;
    }

    if (contfilhos == 0){
        dp[u][1] = INF;
        soma[u] = a[u];
        return;
    }

    for (auto v:g[u]) if (v!=p){
        for (int i=0; i<=n; i++){
            if (dp[u][i] < INF) dp[u][i] += dp[v][i];
        }
    }
    ll diff = a[u] - soma[u];
    ll diffOriginal = diff;
    for (ll i=0; i<=n; i++){
        if (diff <=0 ) break;
        if (dp[u][i] >= INF){
            resp += diff*i;
            diff = 0;
            break;
        }
        ll quant = min(diff, (ll)dp[u][i]);
        diff -= quant;
        dp[u][i] -= quant;
        resp += quant*i;
    }
    for (int i=n; i>0; i--){
        dp[u][i] = dp[u][i-1];
    }
    soma[u] = a[u];
    dp[u][1] = max((ll)dp[u][1], -diffOriginal);

}


void init(){
    resp = 0;
    for (int i=0; i<n+10; i++){
        g[i].clear();
        a[i] = 0;
        soma[i] = 0;
    
        for (int j=0; j<n+10; j++){
            dp[i][j] = 0;
        }
    }
}

void solve(){
    cin >> n;
    init();
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        int p;
        cin >> p;
        p--;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(0,-1);
    cout << resp << endl;
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