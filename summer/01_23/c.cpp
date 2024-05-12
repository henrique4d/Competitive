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
const int MAX = 4e5 + 10;
vector<pair<int,int>> g[MAX];
vector<int> bct[MAX];
bool bridge[MAX];
int pre[MAX];
int low[MAX];
int compVert[MAX];
int compEdg[MAX];
int usedEdg[MAX];
bool used[MAX];
int n,m,a,b,q;
int t = 1;
int c = 1;
stack<int> stc;


int pos[MAX], h[MAX], sz[MAX];
int pai[MAX];
void build(int k, int p = -1, int f = 1) {
	pos[k] = t++; sz[k] = 1;
	for (int& i : bct[k]) if (i != p) {
		pai[i] = k;
		h[i] = (i == bct[k][0] ? h[k] : i);
		build(i, k, f); sz[k] += sz[i];
		
		if (sz[i] > sz[bct[k][0]] or bct[k][0] == p) swap(i, bct[k][0]);
	}
	if (p*f == -1) t = 0, h[k] = k, build(k, -1, 0);
}
int lca(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
	return h[a] == h[b] ? b : lca(pai[h[a]], b);
}
bool anc(int a, int b) {
	return pos[a] <= pos[b] and pos[b] <= pos[a]+sz[a]-1;
}


void dfs(int u, int p){
    pre[u] = low[u] = t++;
    int contfilhos = 0;
    for (auto [v,e]:g[u]){
        if (used[e]) continue;
        used[e] = true;
        stc.push(e);
        if (!pre[v]){
            dfs(v,u);
            contfilhos++;
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], pre[v]);
        }

        if (low[v] >= pre[u] and (u != 0 or contfilhos >= 2)){
            if (!compVert[u]){
                compVert[u] = c++;
                bridge[u] = true;
            }
            int atual;
            do{
                atual = stc.top();
                stc.pop();
                compEdg[atual] = c;
            }while(atual!=e);
            c++;
        }
    }
}


void solve(){
    cin >> n >> m >> q;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    dfs(0,-1);

    while (!stc.empty()){
        compEdg[stc.top()] = c;
        stc.pop();
    }
    c++;


    for (int i=0; i<n; i++){
        if (!compVert[i]) compVert[i] = compEdg[g[i][0].second];
        else{
            for (auto [v,e] : g[i]){
                if (!usedEdg[compEdg[e]]){
                    usedEdg[compEdg[e]] = true;
                    bct[compEdg[e]].push_back(compVert[i]);
                    bct[compVert[i]].push_back(compEdg[e]);
                }
            }
            for (auto [v,e] : g[i]){
                usedEdg[compEdg[e]] = false;
            }
        }
    }
    t = 1;
    build(1);

    while (q--){
        cin >> a >> b >> c;
        a--,b--,c--;
        if (a == c or b == c){
            no();
            continue;
        }
        if (!bridge[c]){
            yes();
            continue;
        }

        if (compVert[a] == compVert[b] or compVert[a] == compVert[c] or compVert[b] == compVert[c]){
            yes();
            continue;
        }
        int ac = lca(compVert[a], compVert[c]);
        int bc = lca(compVert[b], compVert[c]);
        int ab = lca(compVert[a], compVert[b]);        
        if (lca(ab, compVert[c]) == ab and (ac == compVert[c] or bc == compVert[c])){
            no();
        }
        else yes();
    }

}

int main() {
    optimize; 
    ll T = 1;
    // in >> T;
    while(T--) {
        solve();
    }
    return 0;
}