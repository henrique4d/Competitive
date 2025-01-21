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
#define MOD 998244353LL
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

const ll MAXN = 1e5+10;
ll st[4*MAXN];
ll lazy[4*MAXN];



void push(ll v){
    st[2*v] = min(st[2*v], lazy[v]);
    st[2*v+1] = min(st[2*v+1], lazy[v]);

    lazy[2*v] = min(lazy[2*v], lazy[v]);
    lazy[2*v+1] = min(lazy[2*v+1], lazy[v]);

    lazy[v] = INFLL;
}

void build(ll v, ll tl, ll tr){
    lazy[v] = INFLL;
    if (tl == tr){
        st[v] = INFLL;
        return;
    }

    ll tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = min(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val){
    if (l > r) return;

    if (tl == l and tr == r){
        st[v] = min( st[v], val);
        lazy[v] = min(lazy[v],val);
        return;
    }
    push(v);
    ll tm = tl + (tr-tl)/2;
    update(2*v, tl, tm, l, min(r,tm), val);
    update(2*v+1, tm+1,tr, max(l,tm+1),r,val);
    st[v] = min(st[v*2], st[v*2+1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l>r) return INFLL;
    if (l == tl and r == tr) return st[v];
    push(v);
    ll tm = tl + (tr-tl)/2;
    return min(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}



void solve(){
    ll n, inicial;
    cin >> n >> inicial;
    vector<ll> a(n+1,0);
    vector<ll> tabaco(n+1);

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<=n; i++){
        cin >> tabaco[i];
    }

    build(1,0,n);

    auto it = upper_bound(all(a), inicial);
    it--;

    update(1,0,n,0,it-a.begin(),0);

    for (int i=1; i<=n;i++){
        ll val = query(1,0,n,i,i);
        // cout << i << " " << val << endl;
        if (val == INFLL){
            cout << -1 << endl;
            return;
        }
        it = upper_bound(all(a), a[i] + tabaco[i]);
        it--;

        // cout << "chamando update ate " << it-a.begin() << endl;
        update(1,0,n,0,it-a.begin(),val+1);
    }

    cout << query(1,0,n,n,n) << endl;

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