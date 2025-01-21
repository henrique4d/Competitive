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

ll n,k;
string s;
    

bool check(ll p){
    if (s.back() == '.') s.pop_back();
    string aux = "";
    for (ll i=p+1; i<n; i++){
        aux.push_back(s[i]);
    }
    for (ll i=p; i>=0; i--){
        aux.push_back(s[i]);
    }
    // cout << aux << endl;

    for (ll i=0; i<n; i++){
        if (i+k <n and aux[i] == aux[i+k]){
            return false;
        }
    }
    
    for (ll i=0; i<n/k; i++){
        char c = aux[i*k];
        for (ll j=0;j<k; j++){
            if (aux[i*k + j] != c) return false;
        }
    }

    return true;
}

void solve(){
    cin >> n >> k;
    cin >> s;
    ll cont_atual = 1;
    s.push_back('.');
    for (ll i=1; i<n+1; i++){
        if (s[i] == s[i-1]) cont_atual++;
        else{
            if (cont_atual != k){
                if (check(i-1)){
                    cout << i << endl;
                }
                else if (check(i - cont_atual)){
                    cout << i-cont_atual + 1 << endl;
                }
                else if (cont_atual > k and check(i - cont_atual + k -1)){
                    cout << i - cont_atual + k << endl;
                }
                else if (cont_atual > k and check(i - k-1)){
                    cout << i-k << endl;
                }
                else cout << -1 << endl;
                
                return;
            }

            cont_atual = 1;
        }
    }
    cout << n << endl;
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