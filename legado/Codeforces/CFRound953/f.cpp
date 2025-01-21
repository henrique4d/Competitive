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
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const ll MAXN = 1e6+10;
ll dive[MAXN];
vector<ll> app[MAXN];

ll n,k;

struct dsu {
	vector<int> id, sz;

	dsu(int n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
	}
};


void crivo(){
    for (int i=1; i<MAXN; i++) dive[i] = 1;
    for (int i=2; i<MAXN; i++) if (dive[i] == 1) for (int j=i; j<MAXN; j+=i) dive[j] = i;
}


void solve(){
    cin >> n >> k;
    vector<ll> a(n);
    set<ll> to_reset;
    ll cont1 = 0;
    ll resp = 2*n-1;

    for (int i=0; i<n; i++){
        cin >> a[i];
        if (a[i] == 1){
            if (i) resp += n-2;
            else resp += n-1;
        }
        cont1 += a[i] == 1;
    }
    reverse(all(a));
    for (int i=0; i<=n-2; i++) a.push_back(a[i]);

    dsu DS(a.size());

    for (int i=0; i<a.size(); i++){
        while (a[i] > 1){
            app[dive[a[i]]].push_back(i);
            to_reset.insert(dive[a[i]]);
            int divisor = dive[a[i]];
            while (a[i]%divisor == 0) a[i]/=divisor;
        }
    }


    for (auto i:to_reset){
        for (int j =0; j<(int)app[i].size()-1; j++){
            if (app[i][j+1] - app[i][j] <= k){
                if (DS.find(app[i][j]) != DS.find(app[i][j+1])) resp--;
                DS.unite(app[i][j], app[i][j+1]);
            }
        }
    }

    for (auto x:to_reset) app[x].clear();

    cout << resp << endl;
}

int main() {
    optimize;
    crivo();
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}