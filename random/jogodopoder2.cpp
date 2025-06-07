#include <bits/stdc++.h>
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

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
vector<vector<ll>> a;
vector<vector<ll>> ans;

ll n,m;

struct dsu {
	vector<ll> id, sz, value;
    vector<vector<pair<ll,ll>>> elements;

	dsu(ll n) : id(n), sz(n, 1) {
        iota(id.begin(), id.end(), 0);
        value.resize(n,0);
        elements.resize(n);

        for (int i=0; i<n; i++){
            value[i] = a[i/m][i%m];
            elements[i].push_back({i/m, i%m});
        }
    }

	ll find(ll a) { return a == id[a] ? a : id[a] = find(id[a]); }

	void unite(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (sz[a] < sz[b]) swap(a, b);
        if (elements[a].size() < elements[b].size()) swap(elements[a], elements[b]);
        for (auto e:elements[b]){
            elements[a].push_back(e);
        }
        elements[b].clear();
        sz[a] += sz[b], id[b] = a;
        value[a] += value[b];
    }
};



void solve(){
    cin >> n >> m;
    a.resize(n, vector<ll>(m));
    ans.resize(n, vector<ll>(m));
    vector<pair<ll,pair<ll,ll>>> elements;
    ll soma = 0;

    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
            soma += a[i][j];
            elements.push_back({a[i][j],{i,j}});
        }
    }
    dsu D(n*m);

    sort(all(elements));

    for (int k=0; k<elements.size(); k++){
        ll i = elements[k].second.first;
        ll j = elements[k].second.second;
        ll di = -1;
        ll dj = 0;
        int cont = 4;
        ll id = D.find(i*m + j);
        while (cont--){
            if (i + di >= 0 and i + di < n and j+dj >=0 and j + dj < m){
                if (a[i+di][j+dj] <= a[i][j]){
                    if (D.value[D.find((i+di)*m + j+dj)] < a[i][j]){
                        ll idB = D.find((i+di)*m + j+dj);
                        for (auto [x,y] : D.elements[idB]){
                            ans[x][y] = D.value[idB];
                        }
                        D.elements[idB].clear();
                    }
                    D.unite(i*m + j, (i+di)*m + j+dj);

                }
            }
            swap(di, dj);
            dj*=-1;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << (ans[i][j]?ans[i][j]:soma) << " ";
        }
        cout << endl;
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