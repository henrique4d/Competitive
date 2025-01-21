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

const int MAXPRIME = 32000;
vector<int> primes;
bool notprim[MAXPRIME];
int n,m;

const int MAXN = 120;
int val[MAXN];
bool neighbor[MAXN][MAXN];

void crivo(){
    for (ll i = 2; i<MAXPRIME; i++){
        if (notprim[i]) continue;
        for (ll j = i*i; j<MAXPRIME; j+=i){
            notprim[j] = true;
        }
        primes.push_back(i);
    }
}


vector<pair<int,int>> setA;
vector<pair<int,int>> setB;
struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};

void solve(){
    crivo();
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> val[i];
    }
    int u,v;
    
    for (int i=0; i<m; i++){
        cin >> u >> v;
        u--,v--;
        
        neighbor[u][v] = true;
        neighbor[v][u] = true;
    }

    for (int i=0; i<n; i++){
        for (auto p:primes){
            while (val[i]%p == 0){
                val[i]/=p;
                if (i&1) setB.push_back({i,p});
                else setA.push_back({i,p});
            }
        }
        if (val[i] != 1){
            if (i&1) setB.push_back({i,val[i]});
            else setA.push_back({i,val[i]});
        }
    }
    kuhn matching(setA.size(), setB.size());
    for (int i=0; i<setA.size(); i++){
        for (int j=0; j<setB.size(); j++){
            if (setA[i].second == setB[j].second and neighbor[setA[i].first][setB[j].first]){
                matching.add(i,j);
            }
        }
    }

    cout << matching.matching() << endl;
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