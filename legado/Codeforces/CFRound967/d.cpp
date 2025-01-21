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

#define ms(x,a) memset(x,a,sizeof(x))
#define all(x) x.begin(),x.end()

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
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
struct node{
    ll val;
    ll index_menor;
    ll index_maior;
};

const ll MAXN = 3e5+10;
node st[4*MAXN];
ll lazy[4*MAXN];
ll elements[MAXN];
ll contDif[MAXN];
ll lastApp[MAXN];
ll n;
vector<int> app[MAXN];

void init(){
    for (int i=0; i<n+10; i++){
        elements[i] = 0;
        lastApp[i] = 0;
        app[i].clear();
    }
}
node combine(node a, node b){
    if (a.val > b.val) return a;
    if (b.val > a.val) return b;
    node resp = a;
    if (elements[b.index_menor] < elements[a.index_menor] ) resp.index_menor = b.index_menor;
    if (elements[b.index_maior] > elements[a.index_maior] ) resp.index_maior = b.index_maior;

    return resp;
}

void push(int v){
    st[2*v].val += lazy[v];
    st[2*v+1].val += lazy[v];

    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    
    lazy[v] = 0; 
}

void build(int v, int tl, int tr){
    lazy[v] = 0;
    if (tl == tr){
        st[v].val = contDif[tl];
        st[v].index_maior = tl;
        st[v].index_menor = tl;
        return;
    }
    ll tm = tl+(tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    st[v] = combine(st[2*v], st[2*v+1]);
}

void update(int v, int tl, int tr, int l, int r, int x){
    if (l > r) return;
    if (tl == l and tr == r){
        st[v].val += x;
        lazy[v] += x;
        return;
    }
    push(v);
    int tm = tl + (tr - tl)/2;
    update(2*v, tl, tm, l, min(r,tm), x);
    update(2*v+1, tm+1, tr, max(l, tm+1), r, x);
    
    st[v] = combine(st[2*v], st[2*v+1]);
}

node query(int v, int tl, int tr, int l, int r){
    
    if (l > r){
        node lixo;
        lixo.val = -10;
        lixo.index_maior = 0;
        lixo.index_menor = 0;
        return lixo;
    }
    if (tl == l and tr == r){
        return st[v];
    }
    push(v);
    int tm = tl + (tr-tl)/2;    
    return combine(query(2*v, tl, tm, l, min(r,tm)), query(2*v+1, tm+1, tr, max(l, tm+1),r));
}



void solve(){
    cin >> n;
    init();
    for (int i=0; i<n; i++){
        cin >> elements[i];
        app[elements[i]].push_back(i);
    }
    set<int> s;
    for (ll i=n-1; i>=0; i--){
        s.insert(elements[i]);
        contDif[i] = s.size();
        lastApp[elements[i]] = max(i, lastApp[elements[i]]);
    }
    build(1,0,n-1);

    vector<int> resp;
    int i =0;
    bool max = true;
    while (i<n){
        auto q = query(1,0,n-1,i,n-1);
        if (q.val <= 0) break;        
        if (max){
            resp.push_back(elements[q.index_maior]);
            update(1,0,n-1,0,lastApp[elements[q.index_maior]], -1);
            for (int pos: app[elements[q.index_maior]]){
                update(1,0,n-1,pos,pos,-INF);
            }
            i = q.index_maior+1;
        }
        else{
            resp.push_back(elements[q.index_menor]);
            update(1,0,n-1,0,lastApp[elements[q.index_menor]], -1);
            for (int pos: app[elements[q.index_menor]]){
                update(1,0,n-1,pos,pos,-INF);
            }
            i = q.index_menor+1;
        }
        max = !max;
    }
    cout << resp.size() << endl;
    for (auto x:resp){
        cout << x << " ";
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