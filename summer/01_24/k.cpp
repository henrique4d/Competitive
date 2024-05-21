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
struct sat {
	int n, tot;
	vector<vector<int>> g;
	vector<int> vis, comp, id, ans;
	stack<int> s;
 
	sat() {}
	sat(int n_) : n(n_), tot(n), g(2*n) {}
 
	int dfs(int i, int& t) {
		int lo = id[i] = t++;
		s.push(i), vis[i] = 2;
		for (int j : g[i]) {
			if (!vis[j]) lo = min(lo, dfs(j, t));
			else if (vis[j] == 2) lo = min(lo, id[j]);
		}
		if (lo == id[i]) while (1) {
			int u = s.top(); s.pop();
			vis[u] = 1, comp[u] = i;
			if ((u>>1) < n and ans[u>>1] == -1) ans[u>>1] = ~u&1;
			if (u == i) break;
		}
		return lo;
	}
 
	void add_impl(int x, int y) { // x -> y = !x ou y
		x = x >= 0 ? 2*x : -2*x-1;
		y = y >= 0 ? 2*y : -2*y-1;
		g[x].push_back(y);
		g[y^1].push_back(x^1);
	}
	void add_cl(int x, int y) { // x ou y
		add_impl(~x, y);
	}
	void add_xor(int x, int y) { // x xor y
		add_cl(x, y), add_cl(~x, ~y);
	}
	void add_eq(int x, int y) { // x = y
		add_xor(~x, y);
	}
	void add_true(int x) { // x = T
		add_impl(~x, x);
	}
	void at_most_one(vector<int> v) { // no max um verdadeiro
		g.resize(2*(tot+v.size()));
		for (int i = 0; i < v.size(); i++) {
			add_impl(tot+i, ~v[i]);
			if (i) {
				add_impl(tot+i, tot+i-1);
				add_impl(v[i], tot+i-1);
			}
		}
		tot += v.size();
	}
 
	pair<bool, vector<int>> solve() {
		ans = vector<int>(n, -1);
		int t = 0;
		vis = comp = id = vector<int>(2*tot, 0);
		for (int i = 0; i < 2*tot; i++) if (!vis[i]) dfs(i, t);
		for (int i = 0; i < tot; i++)
			if (comp[2*i] == comp[2*i+1]) return {false, {}};
		return {true, ans};
	}
};

const int MAXN = 2e4+10;
vector<pair<int,int>> event;
int n,x,y;
pair<int,int> flag[MAXN];
int pos_seg[MAXN];
sat st;


void build(int v, int tl, int tr){
    if (tl == tr){
        pos_seg[tl] = v;
        return;
    }
    int tm = tl + (tr-tl)/2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);

    st.add_impl(~v, ~(2*v));
    st.add_impl(~v, ~(2*v+1));
}

void update(int v, int tl, int tr, int l, int r, int orig){
    if (l > r) return;
    if (l == tl and r == tr){
        st.add_impl(orig, ~v);
        return;
    }
    int tm = tl + (tr-tl)/2;

    update(2*v, tl, tm, l, min(tm, r), orig);
    update(2*v+1,tm+1, tr, max(l, tm+1), r, orig);
}


bool eval(int x){
    st = sat(4*event.size()+10);
    build(1,0,event.size()-1);

    for (int i=0; i<n; i++){
        st.add_cl(pos_seg[flag[i].first],pos_seg[flag[i].second]);
    }

    for (int i=0; i<event.size(); i++){
        pair<int,int> aux = {event[i].first+x, 0};
        auto it = lower_bound(all(event), aux);
        it--;
        int pos = it - event.begin();
        update(1,0,event.size()-1, i+1, pos, pos_seg[i]);
    }

    return st.solve().first;
}


void solve(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x >> y;
        event.push_back({x,i});
        event.push_back({y,i});
        flag[i] = {-1,-1};
    }

    sort(all(event));

    for (int i=0; i<event.size(); i++){
        auto [pos,fl] = event[i];
        if (flag[fl].first == -1) flag[fl].first = i;
        else flag[fl].second = i;
    }

    int l = 0;
    int r = INF;
    int m;
    while (r-l > 1){
        m = l + (r-l)/2;
        if (eval(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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