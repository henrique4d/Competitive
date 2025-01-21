#include<bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define endl "\n"

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
const ll MAXN = 500;
struct Edge{
    int from, to, capacity, cost;
};

vector<int> adj[MAXN];
int cost[MAXN][MAXN];
int capacity[MAXN][MAXN];
int p[MAXN];
int d[MAXN];
int n;
vector<Edge> edg;

void initPaths(){
    for (int i=0; i<2*n+10; i++){
        d[i] = INF;
        p[i] = -1;
    }
}

void shortest_path(int v0){
    initPaths();
    d[v0] = 0;
    vector<bool> inq(2*n+10, false);
    queue<int> q;
    q.push(v0);

    while (!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v:adj[u]){
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]){
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]){
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int K, int s, int t){
    for (auto e: edg){
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    while (flow < K){
        // cout << flow << endl;
        shortest_path(s);
        
        if (d[t] == INF) break;
    
        int f = K - flow;

        int cur = t;

        while (cur != s){
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        flow += f;
        cost += f*d[t];
        cur = t;
       
        while (cur!=s){
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }

    }

    return cost;
}


void solve(){
    cin >> n;

    int val;
    Edge aux;
    for (int i=1; i<=n; i++){
        aux.from = 0;
        aux.capacity = 1;
        aux.to = i;
        aux.cost = 0;
        edg.push_back(aux);

        for (int j=n+1; j<=2*n; j++){
            cin >> val;
            aux.from = i;
            aux.to = j;
            aux.capacity = 1;
            aux.cost = val;
            edg.push_back(aux);
        }

    }

    for (int j=n+1; j<=2*n; j++){
        aux.from = j;
        aux.capacity = 1;
        aux.to = 2*n+1;
        aux.cost = 0;
        edg.push_back(aux);
    }

    cout << min_cost_flow(INF, 0, 2*n+1) << endl;
    vector<int> resp(n+5);
    for (int i=1; i<=n; i++){
        for (int j=n+1; j<=2*n; j++){
            if (capacity[j][i]) resp[i] = j-n;
        }
    }
    for (int i=1; i<=n; i++){
        cout << i << " " << resp[i] << endl;
    }
    return;
}

int main() {
    // optimize; 
    ll T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}