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
ll a[MAXN];

bool eval(int pos, int x){
    ll g = 0;
    for (int i=pos; i<=x; i++){
        g = __gcd(g, a[i]);
    }
    return g==1;
}

void solve(){
    int n;
    cin >> n;
    ll g = 0;
    ll cont1 = 0;
    a[n] = 1;

    for (int i=0; i<n; i++){
        cin >> a[i];
        cont1 += a[i] == 1;
        g = __gcd(g, a[i]);
    }
    if (g != 1){
        cout << -1 << endl;
        return;
    }
    if (cont1){
        cout << n-cont1 << endl;
        return;
    }

    int ans = INF;
    for (int i=0; i<n;i++){
        int l = i-1;
        int r = n;
        while (r-l>1){
            int m = l + (r-l)/2;
            if (eval(i,m)) r = m;
            else l = m;
        }
        if (r == n) continue;
        // cout << i << " " << r << endl;
        ans = min(ans, n+r-i-1);
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