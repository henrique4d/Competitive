#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"

const ll MAXN = 1e5+10;
ll a[MAXN];
vector<ll> g[MAXN];
ll resp[MAXN];
ll sz[MAXN];
ll n,q,u,v,val;
bool root[MAXN];
// BIT
//
// BIT de soma 0-based
// 
// upper_bound(x) retorna o menor p tal que pref(p) > x 
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
// upper_bound - O(log(n))


struct Bit {
	ll n;
	vector<ll> bit;
	Bit(ll _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<ll>& v) : n(v.size()), bit(n + 1) {
		for (ll i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			ll j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(ll i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(ll i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(ll l, ll r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	ll upper_bound(ll x) {
		ll p = 0;
		for (ll i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};
Bit bit(MAXN);

vector<pair<ll,pair<ll,ll>>> query[MAXN];


void dfs(int u){
    sz[u] = 1;
    for (auto v:g[u]){
        dfs(v);
        sz[u] += sz[v];    
    }
}


void dfs2(int u){
    for (auto quer:query[u]){
        ll v = quer.first;
        ll val = quer.second.first;
        ll sobra = quer.second.second;
        bit.update(v,val);
        bit.update(v,sobra);
    }

    resp[u] = bit.upper_bound(a[u]-1);
    
    for (auto quer:query[u]){
        ll v = quer.first;
        ll val = quer.second.first;
        ll sobra = quer.second.second;
        bit.update(v, -sobra);
    }
    for (auto v:g[u]){
        dfs2(v);
    }
    for (auto quer:query[u]){
        ll v = quer.first;
        ll val = quer.second.first;
        ll sobra = quer.second.second;
        bit.update(v,-val);
    }
}

int main(){
    optimize;
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        root[v] = true;
    }
    int raiz = 0;

    for (int i=0; i<n; i++){
        if (!root[i]){
            raiz = i;
            break;
        }
    }
    
    dfs(raiz);
    
    for (int i=0; i<q; i++){
        cin >> u >> val;
        u--;
        query[u].push_back({i, {val/sz[u], val%sz[u]}});
    }

    dfs2(raiz);
    for (int i=0; i<n; i++){
        if (resp[i] == 100010) cout << -1 << endl;        
        else cout << resp[i]+1 << endl;
    }
}