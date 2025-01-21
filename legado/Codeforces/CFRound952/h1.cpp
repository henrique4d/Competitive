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
struct dsu {
	vector<int> id, sz;
	stack<stack<pair<int&, int>>> st;

	dsu(int n) : id(n), sz(n, 1) { 
		iota(id.begin(), id.end(), 0), st.emplace(); 
	}
		
	void save(int &x) { st.top().emplace(x, x); }

	void checkpoint() { st.emplace(); }
	
	void rollback() {
		while(st.top().size()) {
			auto [end, val] = st.top().top(); st.top().pop();
			end = val;
		}
		st.pop();
	}

	int find(int a) { return a == id[a] ? a : find(id[a]); }

	void unite(int a, int b) {
		// cout << "unindo " << a << " " << b << endl;
        a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		save(sz[a]), save(id[b]);
		sz[a] += sz[b], id[b] = a;
	}
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> matriz (n+4, vector<char>(m+4,'.'));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> matriz[i][j];
        }
    }
    dsu D((n+4) * (m+4));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (matriz[i][j] == '#'){
                int aux = 4;
                int di = -1;
                int dj = 0;
                while(aux--){
                    if (matriz[i+di][j+dj] == '#'){
                        D.unite(i*(m+3) + j, (i+di)*(m+3) + j+dj);
                    }
                    swap(di,dj);
                    dj*=-1;
                }
            }
        }
    }
    ll resp = 0;
    for (int i=1; i<=n; i++){
        D.checkpoint();
        for (int j=1; j<=m; j++){
            if (matriz[i-1][j] == '#'){
                D.unite(i*(m+3)+j,(i-1)*(m+3) + j);
            }
            if (matriz[i+1][j] == '#'){
                D.unite(i*(m+3)+j,(i+1)*(m+3) + j);
            }
            if (j > 1){
                D.unite(i*(m+3)+j,i*(m+3) + j-1);
            }
        }
        resp = max(resp, (ll)D.sz[D.find(i*(m+3)+1)]);
        D.rollback();
    }

    for (int j=1; j<=m; j++){
        D.checkpoint();
        for (int i=1; i<=n; i++){
            if (matriz[i][j-1] == '#'){
                D.unite(i*(m+3)+j,(i)*(m+3) + j-1);
            }
            if (matriz[i][j+1] == '#'){
                D.unite(i*(m+3)+j,(i)*(m+3) + j+1);
            }
            if (i > 1){
                D.unite(i*(m+3)+j,(i-1)*(m+3) + j);
            }
        }
        resp = max(resp, (ll)D.sz[D.find(m+3+j)]);
        D.rollback();
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