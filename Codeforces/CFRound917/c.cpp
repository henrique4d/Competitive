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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
#define mod 998244353LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

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
ll a[MAXN];
ll b[MAXN];


void solve(){
    ll n,k,d;
    cin >> n >> k >> d;

    for (ll i=0; i<n; i++){
        cin >> a[i];
    }
    for (ll i=0; i<k; i++){
        cin >> b[i];
        b[i]-=1;
    }

    ll best = (d-1)/2;
    ll cont = 0;
    for (ll j=0; j<n; j++){
        // cout << a[j] << " ";
        if (a[j] == j+1) cont++;
    }
    // cout << endl;
    // cout << cont << endl;
    best = max(best, cont + (d-1)/2);
    

    for (ll i=0; i<2*n; i++){
        cont = 0;        
        for (ll j=0; j<n; j++){
            if (j <= b[i%k]) a[j]++;
            if (a[j] == j+1) cont++;
        }
        // cout << "o cont e " << cont << endl;
        if (d-i-2 < 0) break;
        best = max(best, cont + (d-i-2)/2);
        // cout << i << " " << best << endl;
    }

    cout << best << endl;
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