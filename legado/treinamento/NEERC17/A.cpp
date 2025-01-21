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
void no() { cout<<"No\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
 
const ll MAXN = 6e5+10;
pair<ll,ll> t[4*MAXN];
vector<pair<ll,ll>> poss;
 
void build (ll v, ll tl, ll tr){
    if (tl == tr){
        t[v].first = LONG_MAX;
        t[v].second = LONG_MIN;
    } else{
        ll tm = tl + (tr-tl)/2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v].first = min(t[v*2].first, t[v*2+1].first);
        t[v].second = max(t[v*2].second, t[v*2+1].second);
    }
}
 
void query(ll v, ll tl, ll tr, ll x){
    if (t[v].first > x or t[v].second < x) return;
    if (tl == tr){
        poss.push_back({tl, t[v].second});
        return;
    }
    ll tm = tl + (tr-tl)/2;
    query(v*2, tl, tm, x);
    query(v*2 + 1, tm+1, tr, x);
}
 
void update(ll v, ll tl, ll tr, ll pos, ll new_val_min, ll new_val_max){
    if (tl == tr){
        t[v].first = new_val_min;
        t[v].second = new_val_max;
    } else {
        ll tm = tl + (tr-tl)/2;
        if (pos <= tm) update(2*v, tl, tm, pos, new_val_min, new_val_max);
        else update(2*v + 1, tm+1, tr, pos, new_val_min, new_val_max);
        t[v].first = min(t[v*2].first, t[v*2+1].first);
        t[v].second = max(t[v*2].second, t[v*2+1].second);
    }
}
 
 
bool acertou(ll x1, ll y1, ll x2, ll y2){
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) < y1*y1;
}
 
 
void solve(){
    ll n;
    cin >> n;
    vector<ll> t(n);
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> d;
    vector<ll> posicao(3*n);
    for (ll i=0; i<n; i++){
        cin >> t[i] >> x[i] >> y[i];
        d.push_back(x[i]-y[i]);
        d.push_back(x[i]+y[i]);
        d.push_back(x[i]);
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    
    build(1, 0,3*n-1);
 
    for (ll i=0; i<n; i++){
        if (t[i] == 1){
            ll xaux = x[i];

            ll l = x[i] - y[i];
            ll r = x[i] + y[i];


            l = lower_bound(d.begin(), d.end(), l) - d.begin();
            r = lower_bound(d.begin(), d.end(), r) - d.begin();
            xaux = lower_bound(d.begin(), d.end(), xaux) - d.begin();
            

            update(1, 0, 3*n-1, xaux,l,r);
            posicao[xaux] = i;
        }
        else{
            poss.clear();
            ll xaux = x[i];
            xaux = lower_bound(d.begin(), d.end(), xaux) - d.begin();
            query(1,0,3*n-1, xaux);
            ll resp = -1;
            for (auto it : poss){
                if (acertou( d[it.first] , (d[it.second] - d[it.first]), x[i], y[i])){
                    resp = posicao[it.first] + 1;
                    update(1, 0, 3*n-1, it.first, LONG_MAX, LONG_MIN); 
                }
            }
            cout << resp << endl;
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