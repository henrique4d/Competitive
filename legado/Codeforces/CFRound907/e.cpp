#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define endl "\n"
 
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
const ll MAXN = 5e5+10;

ll a[MAXN];
vector<ll> adj[MAXN];
pair<ll,ll> tour[MAXN];

ll st[4*MAXN];
ll lazy[4*MAXN];

void build(ll v, ll tl, ll tr){
    if (tl == tr){
        st[v] = 0;
        lazy[v] = 0;
        return;
    }
    ll tm = tl + (tr - tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1,tr);
    st[v] = 0;
    lazy[v] = 0;
}

void push(ll v){
    st[2*v] += lazy[v];
    st[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;    
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll x){
    if (l > r) return;
    if (tl == l and tr == r){
        st[v] += x;
        lazy[v] += x;
        return;
    }
    push(v);
    ll tm = tl + (tr-tl)/2;
    update(2*v, tl, tm, l, min(r, tm), x);  
    update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
    st[v] = st[2*v] + st[2*v+1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return 0;
    if (tl == l and tr == r){
        return st[v];
    }
    push(v);
    ll tm = tl + (tr-tl)/2;
    return query(2*v, tl, tm, l, min(r, tm)) + query(2*v+1, tm+1, tr, max(l, tm+1), r);    
}

void setTour(ll u, ll &ct){
    tour[u].first = ct;
    ct++;
    for (auto v:adj[u]){
        setTour(v, ct);
    }
    tour[u].second = ct-1;
}

void solve(){
    ll q, t, v, x, ct = 1;
    cin >> q;
    vector<pair<ll,ll>> queries;
    for (ll i=0; i<q+1; i++){
        adj[i].resize(0);
    }
    while (q--){
        cin >> t;
        if (t == 2){
            cin >> v >> x;
            queries.push_back({v-1,x});
        }
        else{
            cin >> v;
            v--;
            adj[v].push_back(ct);
            queries.push_back({ct, INT_MIN});
        
            ct++;
        }
    }
    ll z = 0;
    setTour(0, z);
    build(1, 0, ct-1);

    for (auto que: queries){
        if (que.second == INT_MIN){
            update(1, 0, ct-1, tour[que.first].first, tour[que.first].second, -query(1,0,ct-1,tour[que.first].first, tour[que.first].first));
        }
        else{
            update(1,0, ct-1, tour[que.first].first, tour[que.first].second, que.second);
        }
    }
    for (ll i=0; i<ct; i++){
        cout << query(1,0,ct-1,tour[i].first, tour[i].first) << " ";
    }
    cout << endl;
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