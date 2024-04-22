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

const ll MAX = 200;
vector<pair<ll,ll>> g[MAX];
ll prod[MAX][MAX];
ll n,m;

vector<ll> dijkstra(ll start){
    priority_queue<pair<ll,ll>> pq;
    vector<ll> dist(n+10, INFLL);
    pq.push({0, start});
    while (!pq.empty()){
        auto [d,u] = pq.top();
        d*=-1;
        pq.pop();
        if (dist[u] != INFLL) continue;
        dist[u] = min(dist[u],d);
        for (auto [v,w]:g[u]){
            if (dist[v] == INFLL){
                pq.push({-(d+w), v});
            }     
        }
    }
    return dist;
}




struct Edge
{
    ll from, to, capacity, cost;
};
vector<vector<ll>> adj, cost, capacity;
void shortest_paths(ll n, ll v0, vector<ll>& d, vector<ll>& p) {
    d.assign(n, INFLL);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<ll> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        inq[u] = false;
        for (ll v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
vector<Edge> edges;

ll min_cost_flow(ll N, ll K, ll s, ll t) {
    adj.assign(N, vector<ll>());
    cost.assign(N, vector<ll>(N, 0));
    capacity.assign(N, vector<ll>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    ll flow = 0;
    ll cost = 0;
    vector<ll> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INFLL)
            break;

        // find max flow on that path
        ll f = K - flow;
        ll cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

void solve(){
    cin >> n >> m;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<m; j++){
            cin >> prod[i][j];
        }
    }   
    ll d = 0;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cin >> d;
            if (d != -1){
                g[j].push_back({i,d});
            }
        }
    }
    Edge aux;
    for (int i=0; i<n; i++){
        aux.from = m+i+1;
        aux.to = m+n+1;
        aux.capacity = 1;
        aux.cost = 0;
        edges.push_back(aux);
        auto dist = dijkstra(i);

        for (ll p = 1; p<=m; p++){
            ll cost = 0;
            for (int j=0; j<n; j++){
                cost += dist[j]*prod[j][p-1];
            }
            aux.from = p;
            aux.to = m+i+1;
            aux.capacity = 1;
            aux.cost = cost;
            edges.push_back(aux);
        }
    }
    for (ll p = 1; p<=m; p++){
        aux.from = 0;
        aux.to = p;
        aux.capacity = 1;
        aux.cost = 0;
        edges.push_back(aux);
    }
    cout << min_cost_flow(m+n+2,m,0,m+n+1) << endl;

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