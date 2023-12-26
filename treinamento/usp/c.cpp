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
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << bitset<10>(x) << ","; cout << "\b}\n"; }
#define MOD 998244353
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

const int p = 31;
const int m = 1e9 + 9;
const int MAXN = 1e5+5;
ll hashA[MAXN];
ll hashB[MAXN];

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
        res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


ll invMod(ll a, ll p){
    return binpow(a, p-2, p);
}

long long compute_hashA(string const& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i=0; i<s.size(); i++){
        char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        hashA[i] = hash_value;
    }
    return hash_value;
}
long long compute_hashB(string const& s) {
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i=0; i<s.size(); i++){
        char c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
        hashB[i] = hash_value;
    }
    return hash_value;
}

long long getHashA(int i, int j){
    ll resp = hashA[j];
    if (i){
        resp -= hashA[i-1];
    }
    resp += m;
    return resp%m;
}

long long getHashB(int i, int j){
    ll resp = hashB[j];
    if (i){
        resp -= hashB[i-1];
    }
    resp += m;
    return resp%m;
}
int n;
bool aval(int i, int j){
    if (i >=n or j >= n) return false;
    cout << "chamando aval para " << i << " " << j << endl;
    return getHashA(i,j) == getHashB(n-j-1,n-i-1);
}
 


void solve(){
    
    cin >> n;
    string s;
    string inv;
    cin >> s;
    inv = s;
    reverse(inv.begin(), inv.end());

    // cout << s << " " << inv << endl;

    compute_hashA(s);
    compute_hashB(inv);
    ll resp = 0;
    for (int i=0; i<n; i++){
        int l = i-1;
        int r = n+10;
        int m;
        while (r-l > 1){
            m = l + (r-l)/2;
            if (aval(i,m)) l = m;
            else r = m;
        }
        cout << "para i " << i << " temos o primeiro erro em " << l+1 << endl;
    
        l = l+1;
        r = n+10;
        int newi = l+1;

        while (r-l > 1){
            m = l + (r-l)/2;
            if (aval(newi,m)) l = m;
            else r = m;
        }
        cout << "para i " << i << " temos o segundo erro em " << l+1 << endl;
   

        l = l+1;
        newi = l+1;
        r = n+10;
        
        while (r-l > 1){
            m = l + (r-l)/2;
            if (aval(newi,m)) l = m;
            else r = m;
        }

        resp += l - i;
        cout << "para i " << i << " temos o terceiro erro em " << l+1 << endl;
    }
    cout << resp << endl;

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