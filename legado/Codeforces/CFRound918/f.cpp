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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
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
const ll MAXN = 4e5 + 10;

vector<ll> st[4*MAXN];
ll a[MAXN];


void build(int v, int tl, int tr){
    st[v].clear();
    if (tl == tr){
        
        st[v].push_back(a[tl]);
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    for (auto it = st[2*v].begin(); it != st[2*v].end(); it++){
        st[v].push_back(*it);
    }
    for (auto it = st[2*v+1].begin(); it != st[2*v+1].end(); it++){
        st[v].push_back(*it);
    }
    sort(all(st[v]));
    
}

ll query(int v, int tl, int tr, int l, int r, ll x){
    if (l > r) return 0;
    if (tl == l and tr == r){
        return lower_bound(all(st[v]), x) - st[v].begin();
    }
    int tm = tl + (tr-tl)/2;

    return query(2*v, tl, tm, l, min(tm, r), x) + query(2*v+1, tm+1, tr, max(l, tm+1), r, x); 
}




void solve(){
    int n;
    cin >> n;
    vector<pair<ll,ll>> p(n);
    vector<ll> aux;
    for (int i=0; i<n; i++){
        cin >> p[i].first >> p[i].second;
        aux.push_back(p[i].first);
        aux.push_back(p[i].second);
    }
    sort(all(aux));
    for (int i=0; i<n; i++){
        p[i].first = lower_bound(all(aux), p[i].first) - aux.begin();
        p[i].second = lower_bound(all(aux), p[i].second) - aux.begin();
        a[p[i].first] = p[i].second;
        a[p[i].second] = INF;
    }

    build(1,0,2*n-1);

    ll resp = 0;
    for (int i=0; i<n; i++){
        // cout << "query de " << p[i].first << " ate " << p[i].second << " " << p[i].second << endl;
        resp += query(1,0,2*n-1,p[i].first, p[i].second, p[i].second);
    }

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