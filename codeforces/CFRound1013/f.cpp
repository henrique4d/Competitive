#include <bits/stdc++.h>
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
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e3+10;
char tab[MAXN][MAXN];
ll prefix[MAXN][MAXN];
ll prefixSide[MAXN][MAXN];
ll prefixSideBack[MAXN][MAXN];

ll dp[MAXN][MAXN];

ll n,m,d;

void init(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            prefix[i][j] = 0;
            prefixSide[i][j] = 0;
            prefixSideBack[i][j] = 0;
            dp[i][j] = 0;

        }
    }
}


void takeMod(ll &x){
    x = (x+mod)%mod;
}

void solve(){
    cin >> n >> m >> d;
    ll dUp = sqrt(d*d - 1);
    // cout << "o dup vale " << dUp << endl;
    init();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> tab[i][j];
            if (tab[i][j] == 'X' and i == n-1){
                dp[i][j] = 1;
            }
        }
    }
    

    for (int i = n-1; i>=0; i--){
        ll fromPrefix = 0;
        
        for (int j=0; j<m; j++){    
            fromPrefix += prefix[i][j];
            takeMod(fromPrefix);

            fromPrefix %= mod;
            if (tab[i][j] == 'X'){
                dp[i][j] += fromPrefix;
                takeMod(dp[i][j]);

                prefixSide[i][j+1] += dp[i][j];
                takeMod(prefixSide[i][j+1]);

                prefixSide[i][min(j+d+1,m+5)] -= dp[i][j];
                takeMod(prefixSide[i][min(j+d+1,m+5)]);


                prefixSideBack[i][j] -= dp[i][j];
                takeMod(prefixSideBack[i][j]);                

                prefixSideBack[i][max(0LL,j-d)] += dp[i][j];
                takeMod(prefixSideBack[i][max(0LL,j-d)]);
            }
        }

        ll fromPrefixSide = 0;
        ll fromPrefixSideBack = 0;        
        for (int j=0; j<m; j++){
            fromPrefixSide += prefixSide[i][j];
            takeMod(fromPrefixSide);

            fromPrefixSideBack += prefixSideBack[i][j];
            takeMod(fromPrefixSideBack);

            if (tab[i][j] == 'X'){
                dp[i][j] += fromPrefixSide;
                takeMod(dp[i][j]);

                dp[i][j] += fromPrefixSideBack;
                takeMod(dp[i][j]);

                if (i){
                    prefix[i-1][max(0LL,j - dUp)] += dp[i][j];
                    takeMod(prefix[i-1][max(0LL,j - dUp)]);
                    prefix[i-1][min(j+dUp+1, m+5)] -= dp[i][j];
                    takeMod(prefix[i-1][min(j+dUp+1, m+5)]);
                }
            }
        }
    }

    ll ans = 0;
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // exit(0);
    for (int j=0; j<m; j++){
        // cout << j << " " << dp[0][j] << endl;
        ans += dp[0][j];
        takeMod(ans);
    }
    cout << ans << endl;
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