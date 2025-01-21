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
const ll MANX = 2e5;
ll contImpar[255];
ll contPar[255];

void init(){
    for (int i=0; i<255; i++){
        contImpar[i] = 0;
        contPar[i] = 0;
    }
}

void solve(){
    init();

    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll maxImpar = 0;
    ll maxPar = 0;
    ll resp = INF;

    if (n&1){
        for (int i=0; i<n; i++){
            if (i%2 == 0) contPar[s[i]]++;
            else contImpar[s[i]]++;    
        }
        ll bestImpar = 0;
        ll bestPar = 0;
        for (int i=0; i<n; i++){
            contPar[s[i]]--;
            if (i){
               contPar[s[i-1]]++; 
            }
            maxImpar = 0;
            maxPar = 0;
            for (int i=0; i<255; i++){
                maxImpar = max(maxImpar, contImpar[i]);
                maxPar = max(maxPar, contPar[i]);
            }          
            // cout << i << " " << maxImpar << " " << maxPar << endl;  
            resp = min(resp, n - maxImpar - maxPar);   
            swap(contImpar, contPar);
        }
        cout << resp << endl;
    }
    else{
        for (int i=0; i<n; i++){
            if (i%2 == 0) contPar[s[i]]++;
            else contImpar[s[i]]++;
        }
        for (int i=0; i<255; i++){
            maxImpar = max(maxImpar, contImpar[i]);
            maxPar = max(maxPar, contPar[i]);
        }
        cout << n - maxImpar - maxPar << endl;
    }

}

int main() {
    optimize; 
    ll T = 1;
    cin >> T;
    init();
    while(T--) {
        solve();
    }
    return 0;
}