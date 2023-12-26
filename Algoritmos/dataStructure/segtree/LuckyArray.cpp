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
const int MAXN = 1e5 + 10;
struct vertex{
    ll cont;
    ll val;
    ll d;
};

vertex combine(vertex a, vertex b){
    vertex resp;
    resp.cont = a.cont + b.cont;
    resp.d = min(a.d, b.d);
    return resp;
}

vertex st[4*MAXN];
ll lazy[4*MAXN];
ll a[MAXN];
vector<ll> lucky;

void push(int v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    st[2*v].d -= lazy[v];
    st[2*v+1].d -= lazy[v];
    lazy[v] = 0;
}

void build(int v, int tl, int tr){
    lazy[v] = 0;
    if (tl == tr){
        st[v].val = a[tl];
        st[v].d = *lower_bound(all(lucky), a[tl]) - a[tl];
        if (st[v].d == 0) st[v].cont = 1;
        else st[v].cont = 0;
        return;
    }
    int tm = tl + (tr - tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = combine(st[2*v], st[2*v+1]);
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    
    if (l <= tl and r >= tr) return st[v].cont;
    
    push(v);
    int tm = tl + (tr - tl)/2;
    ll resp = query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(tm+1,l), r);

    st[v] = combine(st[2*v], st[2*v+1]);
    return resp;

}

void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r) return;
    if (l <= tl and r >= tr){
        if (tl == tr){
            st[v].val += lazy[v] + val;
            st[v].d = *lower_bound(all(lucky), st[v].val) - st[v].val;
            if (st[v].d == 0) st[v].cont = 1;
            else st[v].cont = 0;
            lazy[v] = 0;
            return;
        }
        else if (val + lazy[v] < st[v].d){
            st[v].d -= val + lazy[v];
            lazy[v] += val;
            return;
        }
    }
    int tm = tl + (tr - tl)/2;
    
    push(v);

    update(2*v, tl, tm, l, min(r,tm), val);
    update(2*v+1, tm+1, tr, max(tm+1, l), r, val);
    
    st[v] = combine(st[2*v], st[2*v+1]);
}

void dfs(int val){
    if (val > 1e4) return;
    lucky.push_back(val);
    dfs(10*val + 4);
    dfs(10*val + 7);
}



void solve(){
    int n,m;
    dfs(4), dfs(7);
    lucky.push_back(LONG_MAX);
    cin >> n >> m;
    sort(all(lucky));
    

    for (int i=0; i<n; i++){
        cin >> a[i];
    }
  
    build(1, 0, n-1);
   
    string type;
    int l,r,add;
    for (int i=0; i<m; i++){
        cin >> type;
        if (type == "count"){
            cin >> l >> r;
            l--,r--;
            cout << query(1,0,n-1, l,r) << endl;
        }
        if (type == "add"){
            cin >> l >> r >> add;
            l--,r--;
            update(1,0,n-1,l,r,add);
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