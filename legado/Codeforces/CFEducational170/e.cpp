#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef int ll;
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
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 

const ll MAXN = 510;
ll dp[MAXN][3*MAXN];
ll value[MAXN];
ll valueStart[MAXN];
const ll offset = 520;
ll n,m;

void init(int x){
    for (int i=0; i<MAXN; i++){
        for (int j=0; j<3*MAXN; j++){
            dp[i][j] = x;
        }
    }
}

ll DP(ll pos, ll contador){
    if (dp[pos][contador] != -1) return dp[pos][contador];
    if (pos == n-1) return value[contador];
    dp[pos][contador] = 0;
    for (ll gastando = 0; gastando <= contador; gastando+=2){
        dp[pos][contador] += ((DP(pos+1, contador - gastando)%mod) * (value[gastando]%mod))%mod;
        dp[pos][contador] %= mod;
    }
    return dp[pos][contador];
}

void solve(){
    cin >> n >> m;
    dp[0][0] = 1;
    for (int k=0; k<MAXN;k++){
        init(0);
        dp[0][offset+1] = 1;
        if (k) dp[0][offset-1] = 1;
        for (int i=0; i<m; i++){
            for (int j=-m-2; j<m+2; j++){
                dp[i+1][offset+j+1] += dp[i][offset+j];
                if (j-1 >= -k) dp[i+1][offset+j-1] += dp[i][offset+j];
                dp[i+1][offset+j+1] %= mod;
                dp[i+1][offset+j-1] %= mod;
            }
        }
        value[k] = dp[m-1][offset - k];
        if (k == 0){
            for (int i=0; i<=m; i++){
                valueStart[i] = dp[m-1][offset + i];
            }
        }
    }
    ll ans = 0;
    if (n == 1){
        cout << value[0] << endl;
        return;
    }
    init(-1);
    for (ll i = m/2; i<=m; i++){
        ans += ((valueStart[i - (m - i)]%mod) * (DP(1,i - (m - i))%mod))%mod ;
        ans %= mod;
    }
    cout << ans << endl;
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