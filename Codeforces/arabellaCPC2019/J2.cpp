#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 1e5+10;
vector<ll> u(MAXN, -1);
vector<ll> d(MAXN, -1);
string v;
ll calcD(int i);
int tam = 0;

ll calcU(int i){
    cout << "calcU " << i << " " << u[i] << endl;
    if (i == tam - 1){
        return u[i] =  v[i] - '0';
    }
    if (u[i] != -1) return u[i];
    u[i] = (v[i] - '0') + min(calcU(i+1), 1 + calcD(i+1));
    return u[i];
}

ll calcD(int i){

    cout << "calcD " << i << " " << d[i] << endl;
    
    if (i == tam - 1){
        if (i == 0) return d[i] = 11 - (v[i] - '0');

        return d[i] = 10 - (v[i] - '0');
    }

    if (d[i] =! -1) return d[i];
    
    if (i == 0){
        d[i] = min( 11 - (v[i] - '0') + calcU(i+1), 10 - (v[i] - '0') + calcD(i+1));
    }
    else d[i] = min( 10 - (v[i] - '0') + calcU(i+1), 9 - (v[i] - '0') + calcD(i+1));

    //cout << "calcD " << i << " " << d[i] << endl;

    return d[i];
}

void solve(){
    cin >> v;
    //cout << v << endl;
    //cout << v.size() << endl;
    tam = v.size();
    
    u[tam-1] = v[tam-1] - '0';
    d[tam-1] = 10 - (v[tam-1] - '0');
    if ((tam-1) == 0){
        d[tam-1] = 11 - (v[tam-1] - '0');
    }

    for (int i=tam-2; i>=0; i--){
        u[i] = (v[i] - '0') + min(u[i+1], 1 + d[i+1]);
        if (i == 0){
            d[i] = min( 11 - (v[i] - '0') + u[i+1], 10 - (v[i] - '0') + d[i+1]);
        }
        else d[i] = min( 10 - (v[i] - '0') + u[i+1], 9 - (v[i] - '0') + d[i+1]);
    }

    //cout << u[0] << " " << d[0] << endl;
    cout << min(u[0], d[0]) << endl;
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