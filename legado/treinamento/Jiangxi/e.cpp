'#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pii;
#define ll long long

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

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
// Geometria

const ll MAXN = 2e5+10;
ll a[MAXN];
unordered_map<ll,pair<ll,ll>> xorr;
    

void solve(){
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++){
        cin >> a[i];
    }
    ll n2 = min(n-min(n, (ll)14), (ll)14);
    n = min(n, (ll)14);
    
    ll limit = pow(3,n) -1;
    xorr.clear();
    // cout << " o limite e de " << limit << endl;
    for (ll mask = 0; mask<limit; mask++){
        ll maskA = 0;
        ll maskB = 0;
        ll maskAux = mask;
        ll sumA = 0;
        ll sumB = 0;
        for (ll i=0; i<n; i++){
            if (maskAux%3 == 0){
                maskA |= (1<<i);
                sumA += a[i];
            }
            else if (maskAux%3 == 1){
                maskB |= (1<<i);
                sumB += a[i];
            }

            maskAux/=3;
        }

        if (sumA == sumB){
            cout << __builtin_popcount(maskA) << " ";
            for (ll i=0; i<n; i++){
                if (maskA&(1<<i)) cout << i + 1 << " ";
            }
            cout << endl;
            
            cout << __builtin_popcount(maskB) << " ";
            for (ll i=0; i<n; i++){
                if (maskB&(1<<i)) cout << i + 1 << " ";
            }
            cout << endl;
            return;
        }
        // cout << bitset<13>(maskA) << " " << sumA << endl;
        // cout << bitset<13>(maskB) << " " << sumB << endl;
        // cout << "-----------------------\n";
        xorr[sumA - sumB] = {maskA, maskB};
    }
    ll noriginal = n;
    n = n2;
    limit = pow(3,n) - 1;
    for (ll mask = 0; mask<limit; mask++){
        ll maskA = 0;
        ll maskB = 0;
        ll maskAux = mask;
        ll sumA = 0;
        ll sumB = 0;
        for (ll i=0; i<n; i++){
            if (maskAux%3 == 0){
                maskA |= (1<<(noriginal+i));
                sumA += a[noriginal+i];
            }
            else if (maskAux%3 == 1){
                maskB |= (1<<(noriginal+i));
                sumB += a[noriginal+i];
            }

            maskAux/=3;
        }

        if (xorr[sumB-sumA] != make_pair((ll)0,(ll)0)){
            // cout << sumA << " " << sumB << " " << maskA << " " << maskB << endl;
            // cout << xorr[sumB-sumA] << endl;
            maskA |= xorr[sumB - sumA].first;
            maskB |= xorr[sumB - sumA].second;
            sumA = sumB;
        }
        if (sumA == sumB){
            cout << __builtin_popcount(maskA) << " ";
            for (ll i=0; i<n+noriginal+2; i++){
                if (maskA&(1<<i)) cout << i + 1 << " ";
            }
            cout << endl;
            
            cout << __builtin_popcount(maskB) << " ";
            for (ll i=0; i<n+noriginal+2; i++){
                if (maskB&(1<<i)) cout << i + 1 << " ";
            }
            cout << endl;
            return;
        }
        // xorr[sumB - sumA] = {maskA, maskB};
    }

    cout << -1 << endl;
}

int main() {
    optimize;
    ll T = 1;
    cin >> T;

    while(T--) {
        solve();
    }
    return 0;
}'