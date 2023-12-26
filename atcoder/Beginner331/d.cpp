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
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 2e5 + 10;

ll a[MAXN];
ll aux[MAXN];

void solve(){
    ll n, q;
    cin >> n >> q;
    ll grid[n+1][n+1];
    char aux;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> aux;
            grid[i][j] = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            if (aux == 'B') grid[i][j]++;
            else grid[i][j]++;
        }
    }

    ll A,B,C,D;
    ll resp = 0;
    while(q--){
        cin >> A >> B >> C >> D;
        ll deslocI = C-A;
        ll deslocJ = D-B;
        A++;
        B++;
        C++;
        D++;
        A%=n;
        B%=n;
        if (!A) A = n;
        if (!B) B = n;

        pair<ll,ll> I1 = {A, min(C,n)};
        pair<ll,ll> I2 = {1, n};
        pair<ll,ll> I3 = {1, C%n};
        

        pair<ll,ll> J1 = {B, min(D,n)};
        pair<ll,ll> J2 = {1, n};
        pair<ll,ll> J3 = {1, D%n};
        

        resp += grid[I1.second][J1.second] - grid[I1.first-1][J1.first-1];
        resp += (grid[I1.second][J2.second] - grid[I1.first-1][J2.first-1])*(deslocJ/n);
        resp += grid[I1.second][J3.second] - grid[I1.first-1][J3.first-1];
        
        resp += (grid[I2.second][J1.second] - grid[I2.first-1][J1.first-1])*(deslocI/n);
        resp += ((grid[I2.second][J2.second] - grid[I2.first-1][J2.first-1])*(deslocJ/n))*(deslocI/n);
        resp += (grid[I2.second][J3.second] - grid[I2.first-1][J3.first-1])*(deslocI/n);
        
        resp += grid[I3.second][J1.second] - grid[I3.first-1][J1.first-1];
        resp += (grid[I3.second][J2.second] - grid[I3.first-1][J2.first-1])*(deslocJ/n);
        resp += grid[I3.second][J3.second] - grid[I3.first-1][J3.first-1];
    }

    cout << resp << endl;


}

int main() {
    optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}