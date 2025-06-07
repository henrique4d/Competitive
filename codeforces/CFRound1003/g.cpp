#include <bits/stdc++.h>
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
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5+10;
ll a[MAXN];
bool isPrime[MAXN];
vector<ll> primes;
ll cont[MAXN];
ll n;
void crivo(){
    for (int i=2; i<MAXN; i++){
        isPrime[i] = true;
    }
    for (ll i = 2; i<MAXN; i++){
        if (isPrime[i]){
            primes.push_back(i);
            for (ll j = i*i; j<MAXN; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    cin >> n;
    ll ans = 0;
    ll cont2 = 0;
    ll contp = 0;
    ll cont4 = 0;
    for (int i=0; i<n; i++){
        cin >> a[i];
        if (a[i] == 2) cont2++;
        else if (a[i] == 4) cont4++;
        else if (isPrime[a[i]]) contp++;
        cont[a[i]]++;
        if (a[i] == 2){
            ans += contp + cont4;
        }
        else if (a[i] == 4){
            ans += cont2;
        }
        else if (isPrime[a[i]]){
            ans += contp + cont2;
        }
        else{
            for (auto p:primes){
                if (p > a[i]) break;
                if (a[i]%p == 0 and isPrime[a[i]/p]){
                    ans += cont[a[i]/p];
                }
            }
        }
        cout << i << " " << a[i] << " " << ans << endl;
    }
    cout << ans << endl;
}

int main() {
    optimize;
    crivo();

    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}