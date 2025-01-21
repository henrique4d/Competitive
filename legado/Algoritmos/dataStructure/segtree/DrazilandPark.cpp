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

const int MAXN = 2e5 + 10;
struct vertex{
    ll beg, end, dist, ins;
};

vertex st[4*MAXN];
ll d[MAXN];
ll h[MAXN];

vertex combine(vertex a, vertex b){
    vertex resp;
    if (a.beg == -1) return b;
    if (b.beg == -1) return a;
    resp.beg = max(a.beg + b.dist, b.beg);
    resp.end = max(a.dist + b.end, a.end);
    resp.dist = a.dist + b.dist;
    resp.ins = max({a.beg + b.end, a.ins, b.ins});
    return resp;
}


void build(int v, int tl, int tr){
    if (tl == tr){
        st[v].beg = h[tl]*2 + d[tl];
        st[v].end = h[tl]*2;
        st[v].dist = d[tl];
        st[v].ins = INT_MIN;
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = combine(st[2*v], st[2*v+1]);
}

vertex query(int v, int tl, int tr, int l, int r){
    if (l > r){
        vertex nulo;
        nulo.beg = -1;
        nulo.end = -1;
        nulo.dist = -1;
        nulo.ins = -1;
        return nulo;
    }

    if (tl == l and tr == r){
        return st[v];
    }
    int tm = tl + (tr - tl)/2;

    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(tm+1,l), r));

}





void solve(){
    int n,q;
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> d[i];
        d[i+n] = d[i];
    }
    for (int i=0; i<n; i++){
        cin >> h[i];
        h[i+n] = h[i];
    }
    build(1,0,2*n-1);
    int a,b;
    while (q--){
        cin >> a >> b;
        a--;
        b--;
        vertex resp;
        vertex resp2;
        vertex resp3;

        if (a <= b){
            resp = query(1, 0,2*n-1, 0,min(a,b)-1);
            resp2 = query(1,0,2*n-1, max(a,b)+1, min(a,b)+n-1);
            resp3 = query(1,0,2*n-1, max(a,b) + n + 1, 2*n-1);
            cout << max({resp.ins, resp2.ins, resp3.ins}) << endl;
        }
        else{
            resp = query(1, 0,2*n-1, min(a,b)+1,max(a,b)-1);
            cout << resp.ins << endl;
        }    
        
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