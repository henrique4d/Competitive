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

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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
const ll MAXN = 2e5+10;
const ll MAXK = 26;
ll n,m,q;

ll p[MAXN];
ll previous[MAXN];
ll pai[MAXK][MAXN];
ll st[MAXK][MAXN];
ll lastApp[MAXN];
ll a[MAXN];

void init(){
    for (int i=0; i<m+10; i++){
        lastApp[i] = 0;
        pai[0][i] = 0;
    }
}

void build(){
    for (int i=1; i<=m; i++){
        st[0][i] = a[i];
    }

    for (int k = 1; k<MAXK; k++){
        for (int i = 1; i+(1LL<<k) <=m+1; i++){
            st[k][i] = max(st[k-1][i], st[k-1][i + (1<<(k-1))]);
        }
    }
}

ll query(int l, int r){
    int j = __builtin_clz(1) - __builtin_clz(r-l+1);
    return max(st[j][l], st[j][r - (1LL<<j) + 1]);
}

void solve(){
    cin >> n >> m >> q;
    init();
    for (int i=1; i<=n; i++){
        cin >> p[i];
        if (i > 1) previous[p[i]] = p[i-1];
    }
    previous[p[1]] = p[n];

    int x;
    for (int i=1; i<=m; i++){
        cin >> x;
        pai[0][i] = lastApp[previous[x]];
        lastApp[x] = i;
    }

    for (int k = 1; k<MAXK; k++){
        for (int i=1; i<=m; i++){
            pai[k][i] = pai[k-1][pai[k-1][i]];
        }
    }

    for (int i=1; i<=m; i++){
        int atual = i;
        for (int k=0; k<25; k++){
            if ((n-1)&(1<<k)) atual = pai[k][atual];
        }
        a[i] = atual;
    }
    build();
    int l,r;
    string ans;
    while (q--){
        cin >> l >> r;
        if (query(l,r) >= l) ans += '1';
        else ans += '0';
    }

    cout << ans << endl;
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