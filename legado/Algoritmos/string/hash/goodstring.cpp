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
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 1510;
int hashs[MAXN];
int ksum[MAXN];
int inversos[MAXN];
int goods[256];
int hashs2[MAXN];
int inversos2[MAXN];
set<pair<int,int>> resp;
const int p = 31;
const int m = 1e9 + 9;
const int pp = 53;

ll binpow(ll a, ll b, ll mo) {
    ll res = 1;
    a%= mo;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mo;
        a = (a * a)%mo;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll p2){
    return binpow(a, p2-2, p2);
}

void compute_hash(const string & s){
    ll hash_value = 0;
    ll hash_value2 = 0;
    ll p_pow = 1;
    ll p_pow2 = 1;

    for (ll i=0; i<s.size(); i++){
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        hashs[i] = hash_value;  

        hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * p_pow2) % m;
        hashs2[i] = hash_value2;  
        

        if (i) ksum[i] = ksum[i-1];
        if (!goods[s[i]]) ksum[i]++;
        inversos[i] = inv(p_pow, m);
        inversos2[i] = inv(p_pow2, m);

        p_pow*=p;
        p_pow%=m;

        p_pow2*=pp;
        p_pow2%=m;
    }
}

ll get_hash(ll i, ll j){
    if (i) return ((((ll)hashs[j] - hashs[i-1] + m)%m)*inversos[i])%m;
    return hashs[j];
}

ll get_hash2(ll i, ll j){
    if (i) return ((((ll)hashs2[j] - hashs2[i-1] + m)%m)*inversos2[i])%m;
    return hashs2[j];
}

void solve(){
    string s;
    cin >> s;
     
    string aux;
    cin >> aux;
    for (ll i=0; i<aux.size(); i++){
        if (aux[i] == '1'){
            goods['a' + i] = true;
        }
        else{
            goods['a' + i] = false;
        }
    }
    compute_hash(s);
    ll k;
    cin >> k;
    for (ll i=0; i<s.size(); i++){
        for (ll j=i; j<s.size(); j++){
            ll b = ksum[j];
            if (i) b -= ksum[i-1];
            if (b <= k){
                resp.insert({get_hash(i,j),get_hash2(i,j)});
            }
        }
    }
    cout << resp.size() << endl;
}


int main() {
    optimize;
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}