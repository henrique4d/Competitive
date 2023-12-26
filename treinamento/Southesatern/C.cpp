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
// void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 3e3 + 100;
const int offset = 3000;
ll dp[MAXN][2*MAXN];
ll k[MAXN];
ll color[MAXN];
ll subtree[MAXN];
ll auxiliar[2*MAXN];
vector<ll> neighbor[MAXN];
ll resp = 0;

void dfs(ll v, ll p,int c){
    subtree[v] = 1;
    for (int i= -k[c]; i<=k[c]; i++){
        dp[v][i + offset] = 0;
    }
    if (color[v] == c){
        dp[v][1 + offset] = 1;
    }
    else{
        dp[v][-1 + offset] = 1;
    }
        
    for (auto u:neighbor[v]){
        if (u == p) continue;
        dfs(u,v,c);

        for (int i = -k[c]; i <= k[c]; i++) auxiliar[i + offset] = 0;
        for (ll val1 = -min(k[c], subtree[v]); val1 <= min(k[c], subtree[v]); val1++){
            for (ll val2 = -min(k[c], subtree[u]); val2 <= min(k[c], subtree[u]); val2++){   
                auxiliar[max(val1 + val2, -k[c]) + offset] += ( (dp[v][val1 + offset]%MOD) * (dp[u][val2 + offset]%MOD)%MOD);
                auxiliar[max(val1 + val2, -k[c]) + offset] %= MOD;
            }
        }
        subtree[v] += subtree[u];

        for (int i = -k[c]; i <= k[c]; i++) dp[v][i + offset] = auxiliar[i + offset];
    }

    dp[v][offset]++;

    for (ll val1 = 1; val1<= k[c]; val1++){
        resp += dp[v][val1 +offset]; 
        resp %= MOD;
    }
}

void solve(){
    ll n;
    cin >> n;

    for (ll i=0; i<n ;i++){
        cin >> color[i];
        color[i]--;
        k[color[i]]++;
    }
    ll a,b;
    for (ll i=0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    for (ll i=0; i<n; i++){
        if (!k[i]) continue;
        dfs(0,-1, i);
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