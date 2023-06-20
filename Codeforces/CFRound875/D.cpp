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
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007
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
const ll MAXN = 2e5 + 10;
const ll SQRMAXN = 635;
 
int fr[SQRMAXN][MAXN];
ll a[MAXN], b[MAXN];
 
void solve(){
    int n;
    ll resp = 0;
    cin >> n;
    ll lim = sqrt(2*n);
    
    f(i,0,n){
        cin >> a[i];
    }
    f(i,0,n){
        cin >> b[i];
        if (a[i] <= lim){
            fr[a[i]][b[i]]++;
        }
    }
 
 
    f(i,0,n){
        if (a[i] <= lim and a[i]*a[i] - b[i] >= 0 and a[i]*a[i] - b[i] <= n)
            resp += fr[a[i]][a[i]*a[i] - b[i]];
    }    
    for(int i = 0; i<= lim; i+=2){
        resp -= fr[i][i*i/2];
    }
 
    resp/=2;
    //cout << resp << endl;
    for (ll j=0; j<n; j++){
        for (ll i=0; i<a[j] and i<= lim; i++){
            if (i*a[j]-b[j] >= 0 and i*a[j]-b[j]<=n) resp += fr[i][i*a[j]-b[j]];
        }
    }
    for (int i=0; i<n; i++){
        if (a[i] <= lim) fr[a[i]][b[i]] = 0;
    }
    cout << resp << endl;
}
 
 
int main() {
 
    optimize;
 
    T = 1;
 
    cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}