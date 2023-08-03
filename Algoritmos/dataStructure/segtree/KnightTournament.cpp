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
void yes() { cout<<"Yes\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 3e5 + 5;
int st[4*MAXN];
int lazy[4*MAXN];
void push(int v){
    st[v*2] = min (st[2*v],lazy[v]);
    lazy[v*2] = min (lazy[2*v],lazy[v]);
    st[v*2+1] = min(st[v*2+1],lazy[v]);
    lazy[v*2+1] = min(lazy[2*v+1],lazy[v]);
    lazy[v] = INT_MAX;
}
void build(int v, int tl, int tr){
    lazy[v] = INT_MAX;
    if (tl == tr){
        st[v] = INT_MAX;
        return;
    }
    int tm = tl + (tr - tl)/2;
    build (2*v, tl, tm);
    build (2*v + 1, tm+1, tr);
    st[v] = min(st[2*v], st[2*v+1]);
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r) return;
    if (tl == l and tr == r){
        st[v] = min(val, st[v]);
        lazy[v] = min(val, lazy[v]);
        return;
    }
    push(v);
    int tm = tl + (tr - tl)/2;
    update(2*v, tl, tm, l, min(r, tm), val);
    update(2*v+1, tm+1, tr, max(tm+1,l), r, val);
    st[v] = min(st[2*v], st[2*v+1]);
}
int query(int v, int tl, int tr, int l, int r){
    if (l > r) return INT_MAX;
    if (tl == l and tr == r){
        return st[v];
    }
    push(v);
    int tm = tl + (tr - tl)/2;
    return min(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(tm+1,l), r));
}

void solve(){
    int n, q;
    cin >> n >> q;
    build(1, 0, n-1);
    vector<int> w(n, INT_MAX);

    int l,r,ganhador;
    for (int i=0; i<q; i++){
        cin >> l >> r >> ganhador;
        l--,r--, ganhador--;
        
        update(1,0,n-1,l,ganhador-1, i);
        
        update(1,0,n-1,ganhador+1, r, i);
        
        w[i] = ganhador;
    }
    update(1,0,n-1, ganhador,ganhador,-1);

    for (int i=0; i<n; i++){
        if (i == ganhador) cout << 0 << " ";
        else cout << w[query(1,0,n-1,i,i)]+1 << " ";
    }
    cout << endl;
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