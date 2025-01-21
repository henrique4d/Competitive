#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define endl "\n"
 
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
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5+10;
ll a[MAXN];
ll n;
void solve(){
    cin >> n;
    vector<pair<ll,ll>> ans;
    for (int i=0; i<n; i++){
        cin >> a[i];
        if (i and a[i] == 1 and a[0] != 1){
            swap(a[i], a[0]);
            ans.push_back({0,i});
        }
    }
    ll comeco = 0;
    ll fim = 1;

    for (int i=1; i<n; i++){
        if (a[i] == 1){
            swap(a[i], fim);
            ans.push_back({fim,i});
            fim++;
        }
    }
    for (int i=fim; i<n; i++){
        if (a[i] == 0){
            swap(a[i], a[comeco]);
            ans.push_back({i,comeco});
            comeco++;
        }
    }
    for (int i=1; i<n; i++){
        if (a[i] == 1 and i > fim){
            swap(a[i], fim);
            ans.push_back({fim,i});
            fim++;
        }
    }
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << ans.size() << endl;
    for (auto [x,y]:ans) cout << x+1 << " " << y+1 << endl;
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