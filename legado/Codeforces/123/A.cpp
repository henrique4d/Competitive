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

 
void solve(){
    int n,x,k;
    cin >> n >> k >> x;
    if (x != 1){
        yes();
        cout << n << endl;
        f(i,0,n){
            if (i) cout << " ";
            cout << 1;
        }
        cout << endl;
    }
    else{
        if (k == 1){
            no();
            return;
        }
        if (k == 2){
            if (n%2 == 0){
                yes();
                cout << n/2 << endl;
                f(i,0,n/2){
                    if (i) cout << " ";
                    cout << 2;
                }
                cout << endl;
            }
            else no();
        }
        else{
            if (n == 1) no();
            else{
                yes();
                cout << n/2 << endl;
                while (n > 3){
                    cout << 2 << " ";
                    n-=2;
                }
                if (n == 3){
                    cout << 3 << endl;
                }
                if (n == 2){
                    cout << 2 << endl;
                }
            }
    }
}


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