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

const ll MAXN = 2e5+10;
ll custo[MAXN];
ll livres[MAXN];
ll corrigidas[MAXN];
ll n, d;

bool eval(ll x){
    ll total = 0;
    for (int i=0; i<d+10; i++){
        livres[i] = 0;
        corrigidas[i] = 0;
    }
    livres[0] = x;
    queue<ll> q;
    for (int i=0; i<n; i++){
        q.push(custo[i]);
    }
    for (int i=0; i<=d; i++){
        total += corrigidas[i];
        while (livres[i] and !q.empty()){
            livres[i]--;
            ll final = i + q.front();
            q.pop();
            if ( final <= d){
                livres[final]++;
                corrigidas[final]++;
            }
        }
    }
    return total == n;
}

void solve(){
    cin >> n >> d;
    for (int i=0; i<n; i++){
        cin >> custo[i];
    }
    ll l = -1;
    ll r = INF;
    while (r-l>1){
        ll m = l + (r-l)/2;
        if (eval(m)) r = m;
        else l = m;
    }
    if (r == INF) cout << -1 << endl;
    else cout << r << endl;
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