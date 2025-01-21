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
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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

ll n,m;
string s;
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

ll quant[10];

void solve(){
    cin >> n >> m >> s;
    vector<ll> p(n);
    for (ll i=0; i<n; i++){
        p[i] = i;
    }

    for (ll i=0; i<m; i++){
        quant[s[i]-'a']++;
    }
    ll q1 = 1;
    for (ll i=0; i<n; i++){
        q1*= quant[i];
        q1 %= mod;
    }

    ll last = -1;

    vector<vector<ll>> prob(n, vector<ll>(n,0));


    ll probPerm = 1;
    bool fair = true;

    do{
        vector<ll> cont(n, 0);
        for (ll i=0; i<m; i++){
            if (p[s[i] - 'a'] == 0){
                cont[0]++;
                cont[0]%=mod;
            }
            else{
                cont[p[s[i] - 'a']] += cont[p[s[i] - 'a']-1];
                cont[p[s[i] - 'a']] %= mod;
            }
        }
        for (ll i=0; i<n; i++){
            prob[i][n - 1 - p[i]] += cont[n-1];
            prob[i][n - 1 - p[i]] %= mod;
        }
        probPerm *= cont[n-1];
        probPerm %= mod;
        probPerm *= binpow(q1, mod-2, mod);
        probPerm %= mod;

        if (last != -1 and last != cont[n-1]){
            fair = false;
        }
        last = cont[n-1];

    }while(next_permutation(all(p)));


    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cout << (prob[i][j] * binpow(q1, mod-2, mod))%mod << " ";
        }
        cout << endl;
    }
    cout << (fair?"S\n":"N\n");
    cout << probPerm << endl;
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