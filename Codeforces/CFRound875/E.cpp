#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
ll T,N,M,K;
const int MAXN = 3e5 + 10;

ll fact[MAXN];
map<ll,ll> freq;
map<ll,ll> diff;
uniform_int_distribution<ll> rnd(0,LLONG_MAX);

ll powmod(ll a, ll b, ll p){
    a %= p;
    if (a == 0) return 0;
    ll product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

ll inv(ll a, ll p){
    return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

ll catalan(ll n, ll p){
    return (nCk(2*n,n,p)*inv(n+1, p))%p;
}

void add_interval(ll l, ll r){
    ll hash = rnd(rng);
    diff[l]^= hash;
    diff[r+1]^=hash;
}


void solve(){
    freq.clear();
    diff.clear();
    ll n,k;
    cin >> n >> k;
    
    add_interval(1,n);
    for (int i=0; i<k; i++){
        ll l,r;
        cin >> l >> r;
        add_interval(l,r);
    }

    ll resp = 1;
    ll hash = diff[1];

    for (auto it = next(diff.begin()); it!=diff.end(); it++){
        freq[hash]+= it->first - prev(it)->first;
        hash^=it->second;
    }

    for (auto it = freq.begin(); it!=freq.end(); it++){
        if (it->second%2 == 0){
            resp = resp*catalan(it->second/2,MOD)%MOD;
        }
        else{
            resp = 0;
        }
        
    }

    cout << resp << endl;


}
 
 
int main() {
 
    optimize;
 
    T = 1;
    fact[0] = 1;
    fact[1] = 1;
    f(i,2,MAXN){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}