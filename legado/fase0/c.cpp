#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"
 
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

const ll MAXN = 2e5+10;

pair<ll,ll> st[4*MAXN];
pair<ll,ll> p[MAXN];
pair<ll,ll> prime;
vector<ll> event[MAXN];

void update(ll v, ll tl, ll tr, ll pos){
    if (tl == tr and tl == pos){
        if (st[v].first) st[v].first = 0;
        else st[v].first = p[tl].first;
        
        if (st[v].second) st[v].second = 0;
        else st[v].second = p[tl].second;
        return;
    }
    ll tm = tl + (tr-tl)/2;
    if (pos <= tm) update(2*v, tl, tm, pos);
    else update(2*v+1, tm+1, tr, pos);
    

    st[v].first = (st[2*v].first + st[2*v+1].first)%prime.first;
    st[v].second = (st[2*v].second + st[2*v+1].second)%prime.second;
}

ll getHash(){
    ll resp = st[1].first;
    resp <<=32;
    resp += st[1].second;

    return resp;
}

void init(){
    prime.first = 1e9+7;
    prime.second = 1e9+9;

    p[0].first = 1;
    p[0].second = 1;
    for (int i=1; i<MAXN; i++){
        
        p[i].first = (p[i-1].first*3)%prime.first;
        p[i].second = (p[i-1].second*5)%prime.second;
    }
}

map<ll,ll> cont;
ll resp = 0;

void solve(){
    ll n,m;
    cin >> n >> m;
    init();

    ll a,b;

    for (int i=0; i<m; i++){
        cin >> a >> b;
        event[a+1].push_back(i);
        event[b].push_back(i);
    }
    for (int i=1; i<n; i++){
        for(auto x:event[i]){
            // cout << "fazendo update do conjunto " << x << endl;
            update(1,0,n-1,x);
        }
        ll hash = getHash();
        // cout << i << " " << hash << endl;   
        cont[hash]++;
        resp = max(resp, cont[hash]);
    }    
    cout << resp+1 << endl;
}
 
int main() {
    // optimize;
    
    ll T = 1;
    // cin >> T;
 
    while(T--) {
        solve();           
    }
    return 0;
}