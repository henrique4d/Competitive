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
vector<vector<ll>> dp;
vector<ll> prefix;
vector<ll> a;
vector<vector<ll>> cont;
vector<ll> b;
ll n,m;


ll DP(ll pos1, ll pos2){
    if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
    if (prefix[pos1] == INFLL) return 0;
    if (b[pos2] == 0) return INFLL;

    ll proximaPosicao = upper_bound(all(prefix), prefix[pos1-1] + b[pos2]) - prefix.begin();
    // cout << pos1 << " " << pos2 << " " << proximaPosicao << endl;
    if (proximaPosicao == pos1) return dp[pos1][pos2] = DP(pos1, pos2+1);
    return dp[pos1][pos2] = min(DP(pos1, pos2+1), DP(proximaPosicao, pos2) + m-pos2);
}

void solve(){
    cin >> n >> m;
    dp.clear();
    a.clear();
    b.clear();
    prefix.clear();
    cont.clear();

    dp.resize(n+10, vector<ll>(m+10, INFLL));
    cont.resize(n+10, vector<ll>(m+10, 0));
    prefix.resize(n+10,INFLL);
    a.resize(n+10,0);
    b.resize(m+10,0);
    prefix[0] = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    for (int i=1; i<=m; i++){
        cin >> b[i];
    }
    // cout << a << endl;
    // cout << prefix << endl;
    // cout << b << endl;
    cont[1][1] = 1;
    dp[1][1] = 0;
    for (int i=1; i<=n+1; i++){
        for (int j=1; j<=m; j++){
            //pular para o proximo b
            if (dp[i][j] < dp[i][j+1]){
                dp[i][j+1] = dp[i][j];
                cont[i][j+1] = 0;
            }
            if (dp[i][j] == dp[i][j+1]){
                cont[i][j+1] += cont[i][j];
            }
            
            //pegar o elemento
            ll proximaPosicao = upper_bound(all(prefix), prefix[i-1] + b[j]) - prefix.begin();
            cout << i << " -- " << j << " -- " << proximaPosicao << endl;
            if (proximaPosicao == i) continue;
            if (dp[i][j] + m-j < dp[proximaPosicao][j]){
                dp[proximaPosicao][j] = dp[i][j] + m-j;
                cont[proximaPosicao][j] = 0;
            }
            if (dp[i][j] + m-j == dp[proximaPosicao][j]){
                cont[proximaPosicao][j] += cont[i][j];
            }
            
        }
    }
    ll ans = INFLL;
    ll ways = 0;
    for (int i=1; i<=m; i++){
        if (dp[n+1][i] < ans){
            ans = dp[n+1][i];
            ways = 0;
        }
        if (dp[n+1][i] == ans){
            ways += cont[n+1][i];
        }
    }
    cout << ans << " " << ways << endl;

    for (int i=1; i<=n+1; i++){
        for (int j=1; j<=m; j++){
            cout << i << " " << j << " " << cont[i][j] << endl;
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