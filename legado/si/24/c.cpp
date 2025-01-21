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
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
vector<ll> resp = {0,0,1,1,2,1,-1,1,2,3,3,1,6,1,4,4,5,1,3,1,6,2,5,1,4,-1,6,2,-1,1,14,1,2,5,7,2,3,1,6,2,3,1,13,1,4,6,7,1,5,3,2,3,8,1,12,2,4,2,3,1,10,1,8,2,3,2,11,1,4,3,5,1,8,1,4,4,4,2,10,1,6,4,5,1,5,2,8,6,6,1,9,3,5,3,3,-1,8,1,2,3,4,1,17,1,6,7,5,1,9,1,6,2,8,1,16,2,4,3,9,-1,11,7,4,7,5,2,15,1,2,2,5,1,10,3,6,8,7,1,177,1,4,4,5,-1,8,3,5,5,10,1,176,1,11,5,7,2,7,1,6,3,10,2,3,1,6,8,9,1,174,5,8,2,8,1,15,2,4,3,6,1,51,1,8,3,5,2,14,2,11,2,9,1,12,1,5,5,3,1,13,1,3,2,7,2,9,2,6,8,6,2,51,1,10,5,7,4,9,3,9,3,-1,2,175,1,16,7,5,1,7,1,8,6,10,1,174,2,6,2,6,1,10,1,2,8,10,2,14,6,11,7,10,1,16,3,6,4,5,1,13,7,10,3,7,1,30,2,8,4,7,1,12,1,11,3,5,2,94};

void solve(){
    ll n;
    cin >> n;
    if (resp[n] == -1) cout << "otinifni\n";
    else cout << resp[n] << endl;
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