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

const ll MAXN = 1000;

char tab[MAXN][MAXN];

void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> tab[i][j];
        }
    }

    bool bfr = false;
    bool bfc = false;
    bool blr = false;
    bool blc = false;

    bool wfr = false;
    bool wfc = false;
    bool wlr = false;
    bool wlc = false;

    for (int i=0; i<n; i++){
        if (tab[i][0] == 'B') bfc = true;
        if (tab[i][0] == 'W') wfc = true;

        if (tab[i][m-1] == 'B') blc = true;
        if (tab[i][m-1] == 'W') wlc = true;
    }

    for (int j=0; j<m; j++){
        if (tab[0][j] == 'B') bfr = true;
        if (tab[0][j] == 'W') wfr = true;

        if (tab[n-1][j] == 'B') blr = true;
        if (tab[n-1][j] == 'W') wlr = true;
    }

    bool canB1 = (blc and bfr) or tab[0][m-1] == 'B';
    bool canB2 = (blr and bfc) or tab[n-1][0] == 'B';

    bool canW1 = (wlc and wfr) or tab[0][m-1] == 'W';
    bool canW2 = (wlr and wfc) or tab[n-1][0] == 'W';
    


    if ((canB1 and canB2) or (canW1 and canW2)) yes();
    else no();

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