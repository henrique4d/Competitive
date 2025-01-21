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

const ll MAXN = 2e5+10;
ll a[MAXN];
vector<ll> dp(250, INFLL);
ll aux[40];

void solve(){
    ll n;
    cin >> n;
    if (n <= 105){
        cout << dp[n] << endl;
        return;
    }
    else{
        n-=105;
        ll resp = 7 + (n)/15 + aux[n%15];
        cout << resp << endl;

    }

}

int main() {
    optimize;

    aux[0] = 0;
    aux[1] = 1;
    aux[2] = 2;
    aux[3] = 1;
    aux[4] = 2;
    aux[5] = 1;
    aux[6] = 1;
    aux[7] = 2;
    aux[8] = 2;
    aux[9] = 2;
    aux[10] = 1;
    aux[11] = 2;
    aux[12] = 2;
    aux[13] = 2;
    aux[14] = 3;
    

    dp[0] = 0;
    for (int i=0; i<=200; i++){
        if (dp[i] != INFLL){
            dp[i + 1] = min(dp[i] + 1, dp[i+1]);
            dp[i + 3] = min(dp[i] + 1, dp[i+3]);
            dp[i + 6] = min(dp[i] + 1, dp[i+6]);
            dp[i + 10] = min(dp[i] + 1, dp[i+10]);
            dp[i + 15] = min(dp[i] + 1, dp[i+15]);
        }
    }    
    // for (int i=0; i<200; i++){
    //     cout << i << " " << dp[i] << endl;
    // }
    // return 0;
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}