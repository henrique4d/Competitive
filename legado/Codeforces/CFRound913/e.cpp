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
const ll MAXN = 1e6 + 10;

void solve(){
    ll n;
    cin >> n;

    ll k = 0;
    ll naux;
    naux = n;
    while(naux){
        k += naux%10;
        naux/=10;
    }
    // cout << (ll)log10(n) + 1 << endl;
    ll dp[(ll)log10(n) + 1][10][70];
    for (ll i=0; i<log10(n); i++){
        for(ll j=0; j<10; j++){
            for (ll z=0; z<70; z++){
                dp[i][j][z] = 0;
            }
        }
    }

    dp[(ll)log10(n)][0][k] = 1;

    ll obj;
    for (ll i = (ll)log10(n); i> 0; i--){
        obj = n%10;
        n/=10;
        for (ll j=0; j<10; j++){
            for (ll z=0; z<70; z++){
                // cout << i << " " << j << " " << z << " " << obj << endl;
                if (dp[i][j][z]){
                    for (ll a=0; a<=9; a++){
                        for (ll b=0; b<=9; b++){
                            for (ll c=0; c<=9; c++){
                                if ((a + b + c) %10 == obj){
                                    if (z - a- b- c >= 0){
                                        dp[i-1][(a+b+c)/10][z - a-b-c] += dp[i][j][z];
                                        if (dp[i][j][z]){
                                            // cout << "aqui " << a << " " << b << " " << c << endl;
                                            //cout << i-1 << " " << (a+b+c)/10 << " " <<  z - a-b-c << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }

    
    ll resp = 0;
    for (ll i=0; i<10; i++){
        for (ll z=0; z<11; z++){
            
            if (i + z == n){
                for (ll a=0; a<=9; a++){
                    for (ll b=0; b<=9; b++){
                        for (ll c=0; c<=9; c++){
                            if (a + b + c == z){
                                resp += dp[0][i][z];
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (k == 1){
        resp = 3;
    }
    cout << resp << endl;
    
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