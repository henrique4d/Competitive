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
#define MOD 998244353
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
const int MAXN = 2e5+ 10;
pair<ll,ll> t[4*MAXN];
ll lazy[4*MAXN];
ll a[MAXN];

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    if (a.first < b.first) return a;
    else return b;
}

void build(int v, int tl, int tr){
    lazy[v] = 0;
    t[v] = {INT_MAX,-1};
    if (tl == tr){
        t[v].first = a[tl];
        t[v].second = tl;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v*2, tl, tm);
    build(v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}


void push(int v) {
    t[v*2].first += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1].first += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v].first += addend;
        lazy[v] += addend;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<ll,ll> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {INT_MAX,-1};
    if (l == tl && tr == r)
        return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}




void solve(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    ll k;
    cin >> k;
    build(1,0,n-1);
    vector<ll> resp(n,0);
    vector<ll> final(n,0);
    ll limit = INT_MAX;
    int beg = 0;
    while (true){
        auto best = query(1,0,n-1, beg,n-1);
        
        //cout << beg << " " << limit << " " << best.first << " " << best.second << endl;
        limit = min(limit, k/best.first);
        if (!limit)break;
        resp[best.second] = limit;
        
        k-= limit * best.first;
        
        beg = best.second+1;
        
        update(1,0,n-1,beg, n-1, -best.first);
    }

    ll cont = 0;
    for (int i=n-1; i>=0; i--){
        cont = max(cont,resp[i]);
        final[i] = cont;
    }

    for (int i=0; i<n; i++){
        cout << final[i] << " ";
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