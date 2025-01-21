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
string s;
const ll MAXN = 300;
ll dp[MAXN][MAXN];

void init(){
    for (int i=0; i<s.size()+10; i++){
        for (int j=0; j<s.size()+10; j++){
            dp[i][j] = -1;
        }
    }
}

ll DP(int i, int j){
    if (dp[i][j] != -1) return dp[i][j];
    
    ll resp = j-i+1;
    for (int k=i; k<j; k++){
        resp = min(resp, DP(i,k) + DP(k+1,j));
    }

    // cout << "chamando dp " << i << " " << j << " " << dp[i][j] << endl;

    for (int tam = 1; i + tam-1 <= j; tam++){
        int k = 1;
        while (i+(k+1)*tam-1 <= j and s.substr(i,tam) == s.substr(i+k*tam, tam)){
            resp = min(resp,DP(i,i+tam-1) + DP(i+(k+1)*tam,j));
            k++;
        }
    }
    return dp[i][j] = resp;
}


void solve(){
    cin >> s;
    init();
    cout << DP(0,s.size()-1) << endl;
    // cout << dp[0][0] << " " << dp[1][1] << endl;
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