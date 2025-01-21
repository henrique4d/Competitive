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
const ll MAXN = 2e5+10;
ll n,m,k;
pair<ll,ll> edges[MAXN];
ll typed[MAXN];
vector<ll> g[MAXN];
bool visited[MAXN];
vector<ll> top_sort;
ll shouldBe[MAXN];

void dfs(int u){
    visited[u] = true;
    for (auto v:g[u]) if (!visited[v]) dfs(v);
    top_sort.push_back(u);
}

ll lis(){
    vector<ll> v;
    for (int i=0; i<n; i++){
        if (typed[i] == -1) continue;
        auto it = lower_bound(v.begin(), v.end(), typed[i]);
        if (it == v.end()) v.push_back(typed[i]);
        else *it = typed[i];
    }
    return v.size();
}

void solve(){
    cin >> n >> m >> k;
    ll u,v;
    vector<ll> val;
    for (int i=0; i<m; i++){
        cin >> u >> v;
        edges[i] = {u,v};
        val.push_back(u);
        val.push_back(v);
    }

    for (int i=0; i<n; i++){
        cin >> typed[i];
        val.push_back(typed[i]);
    }

    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());

    for (int i=0; i<m; i++){
        edges[i].first = lower_bound(val.begin(), val.end(), edges[i].first) - val.begin();
        edges[i].second = lower_bound(val.begin(), val.end(), edges[i].second) - val.begin();
        // cout << i << " " << edges[i] << endl;
        g[edges[i].first].push_back(edges[i].second);
    }

    for (int i=0; i<val.size(); i++){
        if (!visited[i] and g[i].size()) dfs(i);
    }
    reverse(all(top_sort));

    // cout << "na ordenacao toplogica temos\n";
    for (int i=0; i<top_sort.size(); i++){
        shouldBe[top_sort[i]] = i;
        // cout << top_sort[i] << " " << " asdfa " << shouldBe[top_sort[i]] << " ";
    }
    // cout << endl;

    for (int i=0; i<n; i++){
        typed[i] = lower_bound(val.begin(), val.end(), typed[i]) - val.begin();
        // cout << i << " - - - " << typed[i] << " " << shouldBe[typed[i]] << endl;
        if (visited[typed[i]]) typed[i] = shouldBe[typed[i]];
        else typed[i] = -1;
    }
    // cout << val.size() << " " << n << " " << lis() << endl;

    // for (int i=0; i<n; i++){
    //     cout << i << " -- " <<typed[i] << endl;
    // }

    ll resp = (n-lis())*2;

    cout << resp << endl;

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