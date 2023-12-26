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
const int MAXN = 1e6 + 10;
pair<ll,ll> hashs[MAXN];
pair<ll,ll> inversos[MAXN];

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
const pair<ll,ll> p = {31,53};
const pair<ll,ll> m = {1e9 + 9, 1e9 + 7};

void compute_hash(string &s){
    pair<ll,ll> hash_value = {0,0};
    pair<ll,ll> p_pow = {1,1};
    pair<ll,ll> inverso;

    for (int i=0; i<s.size(); i++){
        hash_value.first = (hash_value.first + (s[i] - 'a' + 1) * p_pow.first) % m.first;
        inverso.first = inv(p_pow.first, m.first);
        p_pow.first = (p_pow.first * p.first) % m.first;
        
        hash_value.second = (hash_value.second + (s[i] - 'a' + 1) * p_pow.second) % m.second;
        inverso.second = inv(p_pow.second, m.second);
        p_pow.second = (p_pow.second * p.second) % m.second;
        
        hashs[i] = hash_value;
        inversos[i] = inverso;
    }
}

pair<ll,ll> get_hash(ll i, ll j){
    pair<ll,ll> resp;
    if (i) resp.first = ((((ll)hashs[j].first - hashs[i-1].first + m.first)%m.first)*inversos[i].first)%m.first;
    else resp.first = hashs[j].first;
    
    if (i) resp.second = ((((ll)hashs[j].second - hashs[i-1].second + m.second)%m.second)*inversos[i].second)%m.second;
    else resp.second = hashs[j].second;
    
    return resp;
}
int n;

vector<ll> possible;
bool eval(int m){
    int tam = possible[m];
    if (tam == 0) return true;
    pair<ll,ll> h1 = get_hash(0, tam-1);
    pair<ll,ll> h2 = get_hash(n-1-tam+1,n-1);
    if (h1 != h2) return false;
    for (int i=1; i<n; i++){
        if (i + tam-1 >= n-1) break;
        if (get_hash(i, i+tam-1) == h1) return true;
    }
    return false;
}

void solve(){
    string s;
    cin >> s;
    n = s.size();
    compute_hash(s);
    possible.push_back(0);
    for (int i=0; i<s.size(); i++){
        if (get_hash(0,i) == get_hash(n-1-i, n-1)) possible.push_back(i+1);
    }

    int l = -1;
    int r = possible.size();
    int m;
    while ( r-l > 1){
        m = l + (r-l)/2;
        if (eval(m)){
            l = m;
        }
        else {            
            r = m;
        }
    }
    if (possible[l]){
        for (int i=0; i<possible[l]; i++) cout << s[i];
        cout << endl;
    }
    else cout << "Just a legend\n";
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