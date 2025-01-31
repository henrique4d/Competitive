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
#define MOD 998244353LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5+10;
ll canSum[MAXN];
string a,b;
ll n,q,l,r;
void solve(){
    cin >> n;
    cin >> a >> b;
    for (int i=2; i<(int)a.size()-2; i++){
        canSum[i] = canSum[i-1];
        if (a[i] == '1' or (a[i] == '0' and (b[i-1] == '1' or a[i-2] == '0') and (b[i+1] == '1' or a[i+2] == '0') )) canSum[i]++;
    }

    cin >> q;
    ll resp;
    while(q--){
        cin >> l >> r;
        l--,r--;
        if (r-l+1 == 1){
            cout << (a[l] == '1') << endl;
            continue;
        }
        if (r-l+1 == 2){
            cout << (a[l] == '1')+(a[r] == '1') << endl;
            continue;
        }
        if (r-l+1 == 3){
            resp = 0;
            resp += a[l] == '1';
            resp += a[r] == '1';
            resp += a[l+1] == '1' or (b[l] == '1' and b[r] == '1');
            cout << resp << endl;
            continue;
        }
        if (r-l+1 >= 4){
            resp = canSum[r-2] - canSum[l+2-1];
            resp += a[l] == '1';
            resp += a[r] == '1';
            resp += a[l+1] == '1' or (b[l] == '1' and (b[l+2] =='1' or a[l+3] == '0'));
            resp += a[r-1] == '1' or (b[r] == '1' and (b[r-2] =='1' or a[r-3] == '0'));
            
            cout << resp << endl;
            continue;
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