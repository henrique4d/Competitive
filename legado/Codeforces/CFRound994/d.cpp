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
const ll MAXN = 210;
ll dp[MAXN][MAXN][MAXN];
ll values[MAXN][MAXN];
ll n,m,k;
void init(){
    for (int i=0; i<n+10; i++){
        for (int j=0; j<m+10; j++){
            for (int k=0; k<m+10; k++){
                dp[i][j][k] = INFLL;
            }
        }
    }    
}

void solve(){
    cin >> n >> m >> k;
    init();
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> values[i][j];
        }
    }

    dp[0][0][0] = values[0][0];

    for (int i=0; i<n; i++){
        for (int j=0; j<2*m; j++){
            for (int z=0; z<m; z++){
                int auxj = j%m;
                if (i+1 == )
                dp[i+1][z][z] = min(dp[i+1][z][z], dp[i][auxj][z] + values[i+1][z]);

                dp[i][(auxj+1)%m][z] = min(dp[i][(auxj+1)%m][z], dp[i][auxj][z] - values[i][auxj] + values[i][(auxj+1)%m] + k);

                dp[i][(auxj+1)%m][z+1] = min(dp[i][(auxj+1)%m][z+1], dp[i][auxj][z] + values[i][(auxj+1)%m]);
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            for (int z=0; z<m; z++){
                cout << i << " " << j << " " << z << " " << dp[i][j][z] << endl;
            }
        }
    }

    // cout << dp[0][0][0] << endl;
    // cout << dp[0][1][0] << endl;
    // cout << dp[0][2][1] << endl;
    // cout << dp[1][3][1] << endl;
    // cout << dp[1][0][2] << endl;
    // cout << dp[1][1][3] << endl;
    // cout << dp[2][3][3] << endl;


    // cout << dp[1][2][1] << endl;
    // cout << dp[1][3][1] << endl;
    // cout << dp[1][0][2] << endl;
    // cout << dp[1][1][2] << endl;

    ll ans = INFLL;
    for (int i=0; i<m; i++){
        ans = min(ans, dp[n-1][i][m-1]);
    }
    cout << "teste" << ans << endl;
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