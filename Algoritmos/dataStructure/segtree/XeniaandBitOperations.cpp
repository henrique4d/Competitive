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
const int MAXN = 2e5;
int st[4*MAXN];
int a[MAXN];

// chamar a build com n%2
void build(int v, int tl, int tr, bool op){
    if (tl == tr){
        st[v] = a[tl];
        return;
    }
    
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm, !op);
    build(2*v+1, tm+1, tr, !op);
    
    if (op){
        st[v] = (st[2*v]|st[2*v+1]);
    }
    else{
        st[v] = (st[2*v]^st[2*v+1]);
    }

}

void update(int v, int tl, int tr, int pos, int val, bool op){
    if (tl == tr){
        st[v] = val;
        return;
    }
    int tm = tl + (tr-tl)/2;
    
    if (pos <= tm){
        update(2*v, tl, tm, pos, val, !op);
    }
    else{
        update(2*v+1, tm+1, tr, pos, val, !op);
    }
    if (op){
        st[v] = (st[2*v]|st[2*v+1]);
    }
    else{
        st[v] = (st[2*v]^st[2*v+1]);
    }
}


 
void solve(){
    int n,q;
    cin >> n >> q;
    int limite = 1;
    for (int i=0; i<n; i++){
        limite *= 2;
    }
    for (int i=0; i<limite; i++){
        cin >> a[i];
    }
    build(1,0,limite-1,n%2);

    int pos, val;
    while(q--){
        cin >> pos >> val;
        pos--;
        update(1,0,limite-1, pos,val, n%2);
        cout << st[1] << endl;
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