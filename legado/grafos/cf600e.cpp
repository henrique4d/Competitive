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
const ll MAXN = 2e5+10;
vector<ll> g[MAXN];
ll a[MAXN];
ll n;

ll cnt[MAXN];
bool big[MAXN];
ll sz[MAXN];
ll resp[MAXN];
void setSz(ll u, ll p){
    sz[u] = 1;
    for (auto v:g[u]) if (v!=p){
        setSz(v,u);
        sz[u] += sz[v];
    }
}

void add(ll u, ll p, int x, ll &freq, ll &sum){
    cnt [a[u]] += x;
    if (cnt[a[u]] == freq){
        sum += a[u];
    }
    if (cnt[a[u]] > freq){
        sum = a[u];
        freq = cnt[a[u]];
    }
    for (auto v:g[u]){
        if (v!=p and !big[v]){
            add(v,u,x,freq,sum);
        }
    }
}


ll freqGlobal = 0;
ll sumGlobal = 0;

void dfs(ll u, ll p, bool keep){
    ll mx = -1, bigChild = -1;
    for (auto v:g[u]){
        if (v != p and sz[v] > mx){
            mx = sz[v], bigChild = v;
        }
    }


    ll freqOrig = freqGlobal;
    ll sumOrig = sumGlobal;

    for (auto v:g[u]){
        if (v != p and v != bigChild){
            dfs(v,u,0);
        }
    }
    if (bigChild != -1){
        dfs(bigChild, u,1);
        big[bigChild] = 1;
    }
    ll freq = freqGlobal;
    ll sum = sumGlobal;

    add(u, p, 1, freq, sum);

    resp[u] = sum;

    if (bigChild != -1){
        big[bigChild] = false;
    }
    if (!keep){
        add(u,p,-1, freq, sum);
        freqGlobal = freqOrig;
        sumGlobal = sumOrig;
    }
    else{
        freqGlobal = freq;
        sumGlobal = sum;
    }

}


void solve(){
    cin >> n;
    for (ll i=0; i<n; i++){
        cin >> a[i];
    }
    for (ll i=0; i<n-1; i++){
        ll u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    setSz(0,-1);
    dfs(0,-1,true);
    for (int i=0; i<n; i++){
        cout << resp[i] << " ";
    }
    cout << endl;
}

int main() {
    optimize; 
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}