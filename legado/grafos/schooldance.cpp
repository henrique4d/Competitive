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
const ll MAXN = 550*2;

ll capacity[MAXN][MAXN];
vector<ll> adj[MAXN];
ll parent[MAXN];
ll n,m,k,a,b,c;

ll bfs(ll s, ll t){
    fill(parent, parent+n+m+5, -1);
    parent[s] = -2;
    queue<pair<ll,ll>> q;
    q.push({s,INFLL});
    while (!q.empty()){
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next:adj[cur]){
            if (parent[next] == -1 and capacity[cur][next]){
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

ll maxflow(ll s, ll t){
    ll flow = 0;
    ll new_flow;

    while (new_flow = bfs(s,t)){
        flow += new_flow;
        ll cur = t;
        while (cur != s){
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        capacity[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    
    for (int i=1; i<=m; i++){
        capacity[i+n][n+m+1] = 1;

        adj[i+n].push_back(n+m+1);
        adj[n+m+1].push_back(i+n);
    }

    for (int i=0; i<k; i++){
        cin >> a >> b;
        if (!capacity[a][b+n]){
            adj[a].push_back(b+n);
            adj[b+n].push_back(a);
        }
        capacity[a][b+n] = 1;
    }

    cout << maxflow(0,n+m+1) << endl;
    
    for (int i=1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (capacity[j+n][i] > 0) cout << i << " " << j << endl;
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