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
const ll MAXN = 4e5 + 10;
ll st[4*MAXN];
ll lazy[4*MAXN];
ll a[MAXN];

void push(ll v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];

    st[2*v] += lazy[v];
    st[2*v+1] += lazy[v];
    
    lazy[v] = 0;
}
void build(ll v, ll tl, ll tr){
    if (tl == tr){
        st[v] = a[tl];
        lazy[v] = 0;
        return;
    }
    ll tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = min(st[2*v], st[2*v+1]);
}
void update(ll v, ll tl, ll tr, ll l, ll r, ll add){
    if (l > r) return;
    if (tl ==l and tr == r){
        st[v] += add;
        lazy[v] += add;    
        return;
    }
    push(v);
    ll tm = tl + (tr - tl)/2;
    update(2*v, tl, tm, l, min(tm, r), add);
    update(2*v+1, tm+1, tr, max(tm+1, l), r, add);

    st[v] = min(st[2*v], st[2*v+1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return LONG_MAX;
    if (tl ==l and tr == r){
        return st[v];
    }
    push(v);
    ll tm = tl + (tr - tl)/2;
    return min(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(tm+1, l), r));
}

void solve(){
    ll n;
    cin >> n;
    for (ll i=0; i<n;i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    ll q;
    cin >> q;
    ll l,r,add;
    cin.ignore();
    build(1, 0, n-1);
    while (q--){
        stringstream s;
        string line;

        getline(cin, line);
        s << line;
        ll size = 1;
        for (ll i=0; i<line.size(); i++){
            if (line[i] == ' ') size++;
        }
        if (size == 2){
            s >> l >> r;
        
            if (l <= r){
                cout << query(1,0,n-1,l,r ) << endl;
            }
            else{
                cout << min(query(1,0,n-1,l,n-1), query(1,0,n-1,0,r)) << endl;
            }
        }
        else{
            s >> l >> r >> add;
            if (l <= r){
                update(1,0,n-1,l,r,add );
            }
            else{
                update(1,0,n-1,l,n-1,add);
                update(1,0,n-1,0,r,add);
        
            }
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