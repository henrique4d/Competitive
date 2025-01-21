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
const ll MAXN = 5e5+10;
ll cont[MAXN];

struct dsu {
	vector<int> id, sz, collor;
    vector<pair<ll,ll>> neighbors;


	dsu(int n) : id(n), sz(n, 1), collor(n) { iota(id.begin(), id.end(), 0); iota(collor.begin(), collor.end(), 0);
    neighbors.assign(n, {0,0});
    for (int i=1; i<n; i++){
        neighbors[i] = {i,i};
        collor[i] = i;
        cont[i] = 1;
    }}

	int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(int a, int b) {
		a = find(a), b = find(b);
		cont[collor[a]] -= sz[a];
        cont[collor[b]] -= sz[b];

        if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b], id[b] = a;
        neighbors[a].first = min(neighbors[a].first, neighbors[b].first);
        neighbors[a].second = max(neighbors[a].second, neighbors[b].second);
		cont[collor[a]] += sz[a];
    }

    void changeCol(int a, int c){
        // cout << "here\n";
        a = find(a);
        cont[collor[a]] -= sz[a];
        collor[a] = c;
        cont[collor[a]] += sz[a];
        // cout << a << " " << collor[a] << " " << neighbors[a] << endl;
        
        ll leftNeighbor = find(neighbors[a].first - 1);
        while (collor[leftNeighbor] == collor[a]){
            unite(a, leftNeighbor);
            a = find(a);
            leftNeighbor = find(neighbors[a].first - 1);
        }
        
        ll rigthNeighbor = find(neighbors[a].second + 1);
        while (collor[rigthNeighbor] == collor[a]){
            unite(a, rigthNeighbor);
            a = find(a);
            rigthNeighbor = find(neighbors[a].second + 1);
        }
    }
};


void solve(){
    ll n,q;
    cin >> n >> q;
    dsu D(n+5);
    int t,pos,newCol;
    while (q--){
        cin >> t;
        if (t == 1){
            cin >> pos >> newCol;
            D.changeCol(pos,newCol);
        }
        else{
            cin >> pos;
            cout << cont[pos] << endl;
        }
    }
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