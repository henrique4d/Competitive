#include<iostream>
#include<vector>
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
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }

//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 2e5+10;
int parent[MAXN];
int depth[MAXN];

void make_set(int v){
    parent[v] = v;
    depth[v] = 0;
}

int get_set(int v){
    if (v == parent[v]) return v;
    return parent[v] = get_set(parent[v]);
}

void merge(int u, int v){
    int a = get_set(u);
    int b = get_set(v);
    if (a == b) return;
    if (depth[a] < depth[b]){
        swap(b,a);
    }
    parent[b] = a;
    if (depth[a] == depth[b]) depth[a]++;
}

void solve(){
    int n, m, q;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        make_set(i);
    }
    vector<pair<ll,ll>> a(m+10);
    vector<bool> destruidos (m+10, false);
    for (int i=1; i<=m; i++){
        cin >> a[i].first >> a[i].second;
    }
    cin >> q;
    vector<ll> querys(q);
    for (int i=0; i<q; i++){
        cin >> querys[i];
        destruidos[querys[i]] = true;
    }
    
    int cont = n;

    for (int i=1; i<=m; i++){
        if (!destruidos[i]){
            if (get_set(a[i].first) != get_set(a[i].second)) cont--;
            merge(a[i].first, a[i].second);
        }
    }

    vector<ll> resp(q);
    
    for (int i=q-1; i>=0; i--){
        resp[i] = cont;
        if (get_set(a[querys[i]].first) != get_set(a[querys[i]].second)) cont--;
        merge(a[querys[i]].first, a[querys[i]].second);
    }
    for (int i=0; i<q; i++){
        cout << resp[i] << " ";
    }
    cout << endl;

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