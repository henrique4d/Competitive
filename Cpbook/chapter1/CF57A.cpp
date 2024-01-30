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
 
#define mod 1000000007LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

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


void solve(){
    int n;
    cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 == 0 and x2 == 0) or (x1 == n and x2 == n) or (y1 == 0 and y2 == 0) or (y1 ==n  and y2 == n)){
        cout << abs(x2-x1) + abs(y2-y1) << endl;
    }
    else if (x1 == 0 and x2 != n){
        cout << x2 + abs(y2 - y1) << endl;
    }
    else if (x2 == 0 and x1 != n){
        cout << x1 + abs(y1-y2) << endl;
    }
    else if (y1 == 0 and y2 != n){
        cout << y2 + abs(x2 - x1) << endl;
    }
    else if (y2 == 0 and y1 != n){
        cout << y1 + abs(x1-x2) << endl;
    }
    else if (x1 == n and x2 != 0){
        cout << n-x2 + abs(y2 - y1) << endl;
    }
    else if (x2 == n and x1 != 0){
        cout << n-x1 + abs(y1-y2) << endl;
    }
    else if (y1 == n and y2 != 0){
        cout << n-y2 + abs(x2 - x1) << endl;
    }
    else if (y2 == n and y1 != 0){
        cout << n-y1 + abs(x1-x2) << endl;
    }
    else if (x1 == 0 or x2 == 0){
        cout << n + min(y1 + y2, 2*n-y1-y2) << endl;
    }
    else if (y1 == 0 or y2 == 0){
        cout << n + min(x1 +x2, 2*n - x1-x2) << endl;
    }
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