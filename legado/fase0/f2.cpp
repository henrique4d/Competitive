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

const ll MAXN = 5e3+10;
ll dp[MAXN][MAXN];
ll sobrou;

ll fact[MAXN];

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

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

ll catalan(ll n, ll p){
    return (nCk(2*n,n,p)*inv(n+1, p))%p;
}

ll DP(ll pos, ll x){
    if (dp[pos][x] != -1) return dp[pos][x];
    if (pos == sobrou) return 1;
    dp[pos][x] = 0;
    
    for (ll i = 0; i<= x; i++){
        dp[pos][x] += DP(pos+1, x-i);
        dp[pos][x]%=mod;
    }
    
    return dp[pos][x];
}


void init(){
    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            dp[i][j] = -1;
        }
    }
}

void solve(){
    ll n;
    init();
    cin >> n;
    string s;
    cin >> s;

    ll atual = 0;
    ll maiorpositivo = 0;
    ll menornegativo = 0;

    for (auto c:s){
        if (c == '(') atual++;
        else atual--;
        menornegativo = max(menornegativo, -atual);
    }

    reverse(all(s));
    atual = 0;
    for (auto c:s){
        if (c == '(') atual++;
        else atual--;
        maiorpositivo = max(maiorpositivo, atual);
    }

    
    ll tam = maiorpositivo + menornegativo + 1;
    
    
    sobrou = n - maiorpositivo - menornegativo - s.size();

    if (sobrou < 0){
        cout << 0 << endl;
        return;
    }

    ll resp = DP(0,tam);
    // cout << resp << endl;

    resp *= catalan(sobrou/2, mod);
    // cout << "catalan " << catalan(sobrou/2, mod) << endl;
    resp %= mod;

    sobrou -= maiorpositivo + menornegativo + s.size();
    bool somar = false;
    // cout << resp << endl;
    while (sobrou > 0){
        // cout << "--- " << catalan(sobrou/2, mod)*DP(0,tam) << endl;
        if (somar) resp -= catalan(sobrou/2, mod)*DP(0,tam);
        else resp -= catalan(sobrou/2, mod)*DP(0,tam);
        resp += mod;
        resp %= mod;
        sobrou -= maiorpositivo + menornegativo + s.size();
        somar = !somar;
    }

    cout << resp << endl;

}

int main() {
    optimize; 
    ll T = 1;
    fact[0] = 1;
    for( ll i = 1; i< MAXN; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}