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
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 


const ll MAXN = 2e5+10;

pair<ll,ll> st[4*MAXN];
ll a[MAXN];


pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    set<ll> aux;
    aux.insert(a.first);
    aux.insert(a.second);
    aux.insert(b.first);
    aux.insert(b.second);
    if (aux.size() == 1){
        return {*aux.begin(), -INFLL};
    }
    auto it = aux.rbegin();
    auto it2 = it;
    it2++;
    return {*it, *it2};    
}

void build(int v, int tl, int tr){
    if (tl == tr){
        st[v] = {a[tl], -INFLL};
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = combine(st[2*v], st[2*v+1]);
}

void update(int v, int tl, int tr, int p, int x){
    if (tl == tr and tl == p){
        st[v] = {x, -INFLL};
        return;
    }
    int tm = tl + (tr-tl)/2;
    if (p <= tm) update(2*v, tl, tm, p, x);
    else update(2*v+1, tm+1, tr, p, x);

    st[v] = combine(st[2*v], st[2*v+1]);
}

pair<ll,ll> query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return {-INFLL, -INFLL};
    }
    if (tl == l and tr == r){
        return st[v];
    }

    int tm = tl + (tr-tl)/2;

    return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void solve(){
    int n,q;
    cin >> n >> q;
    map<int, ordered_set> m;
    for (int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]].insert(i);
    }

    build (1, 0, n-1);
   
    while (q--){
        int t;
        cin >> t;
        if (t == 1){
            int p, x;
            cin >> p >> x;
            p--;
            // cout << "update " << p << " " << x << endl;
            update(1,0,n-1,p,x);
            m[a[p]].erase(p);
            a[p] = x;
            m[a[p]].insert(p);
        }
        else{
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            int x = query(1,0,n-1, l,r).second;
            // cout << "buscando por " << x << " " << l <<" " << r << endl;
            if (x == -INFLL){
                cout << 0 << endl;
            }
            else{
                cout << m[x].order_of_key(r+1) - m[x].order_of_key(l) << endl;
            }
            // cout << "query " << l << " " << r << " " << query(1,0,n-1,l,r) << endl;
        }
    }

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