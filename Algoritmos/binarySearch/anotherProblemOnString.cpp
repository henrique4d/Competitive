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
#define MAXN 200010
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
ll T,N,M,K;
 
int binarySearc(vector<int> &v, int key){
 
    int l = -1, r = v.size();
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(key < v[m]) {
            r = m; // a[l] <= k < a[m] <= a[r]
        } else {
            l = m; // a[l] <= a[m] <= k < a[r]
        }
    }
    return l;
}
 
void solve(){
    int k;
    string in;
    cin >> k >> in;
    int n = in.size();
    vector<ll> sum(n+1,0);
    for (int i=1; i<=n; i++){
        sum[i] = sum[i-1];
        
        if (in[i-1] == '1') sum[i]++;
    }
    ll resp = 0;

    //cout << sum << endl;
    for (int i=0; i<=n; i++){

        auto it1 = lower_bound(sum.begin()+i+1, sum.end(), k + sum[i]);
        auto it2 = upper_bound(sum.begin()+i+1, sum.end(), k + sum[i]);
        //cout << i << " " << it2-it1 << endl;
        resp += it2- it1;
    }
    //if (k == 0) resp -= n+1;
 
    cout << resp << endl;
}
 
 
int main() {
 
    //optimize;
 
    T = 1;
 
    //cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}