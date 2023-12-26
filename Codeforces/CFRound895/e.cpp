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
#define MOD 998244353
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
const int MAXN = 1e5+10;
pair<ll,ll> a[MAXN];
pair<ll,ll> t[4*MAXN];
bool lazy[4*MAXN];

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    return {a.first ^b.first, a.second^b.second};
}
void push(int v){
    if (lazy[v]){
        swap(t[2*v].first, t[2*v].second);
        swap(t[2*v+1].first, t[2*v+1].second);
        lazy[2*v] = !lazy[2*v];
        lazy[2*v+1] = !lazy[2*v+1];
        lazy[v] = false;
    }
}

void build(int v, int tl, int tr){
    lazy[v] = false;
    if (tl == tr){
        t[v] = a[tl];
        lazy[v] = false;
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

void update(int v, int tl, int tr, int l, int r){
    if (l > r) return;
    if (tl == l and tr == r){
        swap(t[v].first, t[v].second);
        lazy[v] = !lazy[v];
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, min(r, tm));
    update(v*2+1, tm+1, tr, max(l, tm+1), r);

    t[v] = combine(t[v*2], t[v*2+1]);
}

pair<ll,ll> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return {0,0};
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
    vector<ll> val(n);
    ll aux;
    for (int i=0; i<n; i++){
        cin >> val[i];
    }
    string in;
    cin >> in;
    for (int i=0; i<in.size(); i++){
        if (in[i] == '0'){
            a[i].first = val[i];
            a[i].second = 0;
        }
        else{
            a[i].second = val[i];
            a[i].first = 0;
        }
    }
    build(1,0,n-1);    
    int q;
    cin >> q;
    while (q--){
        int tipo;
        cin >> tipo;
        if (tipo == 2){
            int b;
            cin >> b;
            auto resp = query(1,0,n-1,0,n-1);
            if (b) cout << resp.second << " ";
            else cout << resp.first << " ";
        }
        else{
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            update(1,0,n-1,l,r);
        }
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