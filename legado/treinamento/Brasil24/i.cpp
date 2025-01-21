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

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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
const ll MAXM = 1e6+10;
bool isPrimes[MAXM];
vector<int> prime;
ll cont[MAXM];
ll pot2[MAXM];
void crivo(int limit){
    for (int i=2; i<=limit; i++){
        if (!isPrimes[i]) prime.push_back(i);
        isPrimes[i] = true;
        for (int j=i*i; j<=limit; j+=i){
            isPrimes[j] = true;
        }
    }
}

void solve(){
    crivo(1e3+10);
    ll n,q,x;
    cin >> n;
    pot2[0] = 1;
    for (int k=0; k<n; k++){
        if (k){
            pot2[k] = pot2[k-1]*2;
            pot2[k]%= mod;
        }
        cin >> x;

        vector<int> fatores;

        for (auto p:prime){
            if (x%p == 0){
                fatores.push_back(p);
                while (x%p == 0) x/=p;
            }
        }
        if (x != 1) fatores.push_back(x);

        int maskLimit = (1<<fatores.size());
        for (int i=1; i<maskLimit; i++){
            ll p = 1;
            int contfatores = 0;
            for (int j=0; j<fatores.size(); j++){
                if (i & (1<<j)){
                    p *= fatores[j];
                    contfatores++;
                }
            }
            if (contfatores&1){
                cont[p]--;
            }
            else cont[p]++;
        }
    }
    pot2[n] = pot2[n-1]*2;
    pot2[n] %= mod;
   
    cin >> q;
    for (int k=0; k<q; k++){
        ll pot = 0;
        cin >> x;
        vector<int> fatores;
        for (auto p:prime){
            if (x%p == 0){
                fatores.push_back(p);
                while (x%p == 0) x/=p;
            }
        }
        if (x != 1) fatores.push_back(x);

        int maskLimit = (1<<fatores.size());
        for (int i=1; i<maskLimit; i++){
            ll p = 1;
            int contfatores = 0;
            for (int j=0; j<fatores.size(); j++){
                if (i & (1<<j)){
                    p *= fatores[j];
                    contfatores++;
                }
            }
            pot += cont[p];
        }
        cout << pot2[n+pot] << endl;
    }
}

int main() {
    optimize; 
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}