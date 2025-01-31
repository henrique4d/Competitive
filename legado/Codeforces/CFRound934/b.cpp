#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"

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
void yes() { cout<<"YES\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 

void solve(){
    ll n, k;
    cin >> n >> k;
    k*=2;
    vector<vector<ll>> app(n+5);

    ll x;
    for (int i=1; i<=2*n; i++){
        cin >> x;
        // cout << x << endl;
        app[x].push_back(i);
    }

    vector<ll> respA;
    vector<ll> respB;


    vector<ll> sobraA;
    vector<ll> sobraB;

    for (int i=1; i<=n; i++){
        // cout << i << " " << app[i][0] << " " << app[i][1] << endl;
        sort(all(app[i]));
        if (app[i][0] <= n and app[i][1] > n and respA.size() < k){
            respA.push_back(i);
            respB.push_back(i);
        }
        else if (app[i][0] <= n and app[i][1] <= n){
            sobraA.push_back(i);
        }
        else if (app[i][0] > n and app[i][1] > n){
            sobraB.push_back(i);
        }
    }

    for (int i=0; i<sobraA.size(); i++){
        if (respA.size() >= k) break;
        respA.push_back(sobraA[i]);
        respA.push_back(sobraA[i]);
    }

    for (int i=0; i<sobraB.size(); i++){
        if (respB.size() >= k) break;
        respB.push_back(sobraB[i]);
        respB.push_back(sobraB[i]);
    }

    if (respA.size()&1){
        for (int i=1; i<respA.size(); i++){
            cout << respA[i] << " ";
        }
        cout << endl;    
    }
    else{
        for (int i=0; i<respA.size(); i++){
            cout << respA[i] << " ";
        }
        cout << endl;
    }
    
    if (respB.size()&1){
        for (int i=1; i<respB.size(); i++){
            cout << respB[i] << " ";
        }
        cout << endl;
    }
    else{
        for (int i=0; i<respB.size(); i++){
            cout << respB[i] << " ";
        }
        cout << endl;
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