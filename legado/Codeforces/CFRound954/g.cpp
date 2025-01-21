#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef int ll;
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
const ll MAXN = 5e5+10;
pair<ll,ll> a[MAXN];
ll cont[MAXN];


void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> vecA(n+5, vector<ll>());
    vector<vector<ll>> vecB(n+5, vector<ll>());
    vector<ll> respVal(n+5);
    vector<ll> lastVal(n+5, -1);

    long long resp = 0;

    for (int i=1; i<=n; i++){
        a[i].first = i;
        cin >> a[i].second;
        ll g = __gcd(a[i].first, a[i].second);
        a[i].first/=g;
        a[i].second/=g;
        vecA[a[i].first].push_back(i);
        vecB[a[i].second].push_back(i);
        // cout << i << " " << a[i] << endl;
        if (a[i].first == 1) resp--;
    }


    for (int x = 1; x<=n; x++){
        // cout << x << " " << resp << endl;
        for (auto i:vecA[x]){
            cont[a[i].second]++;
        }

        for (int y = x; y<=n; y+=x){
            for (auto i:vecB[y]){ 
                ll val = a[i].first;
                if (lastVal[val] != x){
                    lastVal[val] = x;
                    respVal[val] = 0;
                    for (ll z = a[i].first; z <=n; z+=a[i].first){
                        respVal[val] += cont[z];
                    }
                }
                resp += respVal[val];
            }
        }
        
        for (auto i:vecA[x]){
            cont[a[i].second]--;
        }
    }
    resp/=2;   
    cout << resp << endl;
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