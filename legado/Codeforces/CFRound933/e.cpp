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
const ll MAXN = 2e5+10;
ll a[MAXN];

ll st[MAXN*4];

void build(ll v, ll tl, ll tr){
    if (tl == tr){
        st[v] = INFLL;
        return;
    }
    ll tm = tl + (tr-tl)/2;

    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st[v] = min(st[2*v], st[2*v+1]);
}

void update(ll v, ll tl, ll tr, ll p, ll x){
    if (tl == tr and tl == p){
        st[v] = x;
        return;
    }

    ll tm = tl + (tr-tl)/2;

    if (p <= tm) update(2*v, tl, tm, p, x);
    else update(2*v+1, tm+1, tr, p, x);

    st[v] = min(st[2*v], st[2*v+1]);
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if (l > r) return INFLL;
    if (tl == l and tr == r){
        return st[v];
    }
    ll tm = tl + (tr-tl)/2;

    return min( query(2*v, tl, tm, l, min(tm, r)), query(2*v+1, tm+1, tr, max(tm+1, l), r));
}




void solve(){
    ll n, m, k, d;
    cin >> n >> m >> k >> d;
    d++;
    ll val;
    ll custo;
    ll atual = 0;
    ll resp = INFLL;
    queue<ll> q;

    for (int i=0; i<n; i++){
        build(1, 0, m-1);
        for (int j=0; j<m; j++){
            cin >> val;
            if (j == 0){
                // cout << "fazendo update " << 0 << " " << val+1 << endl;
                update(1,0,m-1,0,val+1);
                continue;
            }
            // cout << "realizando a query " << max(j-d,(ll)0) << " " << j-1 << " " << query(1,0,m-1, max(j-d,(ll)0), j-1) << endl;

            custo = query(1,0,m-1, max(j-d,(ll)0), j-1) + val+1;
            // cout << val << " " << custo << endl;
            // cout << i << " " << j << " " << custo << endl;

            update(1,0,m-1,j,custo);
        }
        q.push(custo);
        atual += custo;
        if (q.size() > k){
            atual -= q.front();
            q.pop();
        }
        if (q.size() == k){
            resp = min(resp, atual);
        }
    }
    cout << resp << endl;
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