#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"
 
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
const ll MAXN = 2e5 + 10;
const ll K = 25;
ll a[MAXN];
ll dp[MAXN];
pair<ll,ll> st[K+1][MAXN];

int n;

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    return a.first>b.first?a:b;
}

void build(){
    for (int i=0; i<n; i++){
        st[0][i].first = a[i];
        st[0][i].second = i;
    }
    for (int i=1; i<=K; i++){
        for (int j = 0; j + (1<<i) <= n; j++){
            st[i][j] = combine(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
}
ll log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

pair<ll,ll> get(ll l, ll r){
    int i = log2_floor(r-l+1);
    return combine(st[i][l], st[i][r - (1<<i) + 1]);
}


void solve(){
    cin >> n;
    for (int i=0; i<n-1; i++){
        cin >> a[i];
        a[i]--;
    }
    a[n-1] = n-1;
    dp[n-1] = 0;
    build();
    ll resp = 0;
    for (int i=n-2; i>=0; i--){
        auto [_,m] = get(i+1, a[i]);
        dp[i] = dp[m] - (a[i] - m) + n - i - 1;
        resp += dp[i];
    }
    cout << resp << endl;
}

int main() {
    // optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}