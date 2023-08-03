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
const int MAXN = 1e5+5;
struct vertex{
    int gcd, menor, cont;    
};

vertex st[4*MAXN];
vertex combine(vertex a, vertex b){
    vertex resp;
    resp.gcd = __gcd(a.gcd, b.gcd);
    if (a.menor < b.menor){
        resp.menor = a.menor;
        resp.cont = a.cont;
    }
    if (b.menor < a.menor){
        resp.menor = b.menor;
        resp.cont = b.cont;
    }
    if (a.menor == b.menor){
        resp.menor = a.menor;
        resp.cont = a.cont + b.cont;
    }
    return resp;
}
int a[MAXN];

void build(int v, int tl, int tr){
    if (tl == tr){
        st[v].gcd = a[tl];
        st[v].menor = a[tl];
        st[v].cont = 1;
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = combine(st[2*v], st[2*v+1]);
}


vertex query(int v, int tl, int tr, int l, int r){
    vertex nulo;
    nulo.gcd = 0;
    nulo.menor = INT_MAX;
    nulo.cont = 0;

    if (l > r) return nulo;

    if (tl == l and tr == r){
        return st[v];
    }
    int tm = tl + (tr - tl)/2;
    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(tm+1,l), r));
}

 
void solve(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    build (1,0,n-1);
    int q;
    cin >> q;
    int l,r;
    while(q--){
        cin >> l >> r;
        l--,r--;
        
        vertex res = query(1, 0,n-1, l,r);
        //cout << res.gcd << " " << res.menor << " " << res.cont << endl;
        if (res.gcd % res.menor == 0){
            cout << r-l-res.cont + 1 << endl;
        }
        else cout << r-l+1 << endl;
    }

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