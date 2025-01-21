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
const int MAX = 1e5+10;

vector<pair<int,int>> g[MAX];
int pre[MAX];
int low[MAX];
int comp[MAX];
int color[MAX];
bool visited[MAX];
bool visitedComp[MAX];
bool luck[MAX];
stack<int> stc; 
int n,m,a,b;
int t = 1;
int c = 1;
int root;

ifstream in("D.IN");

void init(){
    for (int i=0; i<max(n,m)+5; i++){
        g[i].clear();
        pre[i] = 0;
        low[i] = 0;
        comp[i] = 0;
        color[i] = 0;
        visited[i] = false;
        visitedComp[i] = false;
        luck[i] = false;
    }
    t = 1;
    c = 1;
}

void dfs(int u, int p){
    pre[u] = low[u] = t++;
    int contfilhos = 0;
    for (auto [v,e]:g[u]) if (v!=p){
        if (pre[v] > pre[u]) continue;
        if (!pre[v]){
            contfilhos++;
            stc.push(e);
            dfs(v,u);
            low[u] = min(low[u], low[v]);
        }
        else if (pre[v] < pre[u]){
            stc.push(e);
            low[u] = min(low[u], pre[v]);
        }

        if (low[v] >= pre[u] and (u != root or contfilhos >= 2)){
            int atual;
            do{
                atual = stc.top();
                stc.pop();
                comp[atual] = c;
            }while (atual != e);
            c++;
        }
    }
}

bool bip(int u, int col, int component){
    color[u] = col;
    for (auto [v,e]:g[u]){
        if (!visited[e] and comp[e] == component){
            visited[e] = true;
            if (color[v] and color[v] == color[u]) return false;

            if (!color[v] and !bip(v, col==1?2:1,component)) return false;
        }
    }
    return true;
}

void clear(int u){
    color[u] = 0;
    for (auto [v,e]: g[u]){
        if (color[v]) clear(v);
    }
}


void solve(){
    in >> n >> m;
    init();
    for (int i=1; i<=m; i++){
        in >> a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    for (int i=1; i<=n; i++){
        if (!pre[i]){
            root = i;
            dfs(i,0);
            while (!stc.empty()){
                comp[stc.top()] = c;
                stc.pop();
            }
            c++;
        }
    }
    ll resp = 0;
    for (int u=1; u<=n; u++){
        for (auto [v,e]: g[u]){
            if (!visitedComp[comp[e]]){
                visitedComp[comp[e]] = true;
                luck[comp[e]] = !bip(u,1,comp[e]);

                clear(u);
            }
            if (luck[comp[e]]){
                resp++;
                break;
            }
        }
    }
    cout << resp << endl;
}

int main() {
    optimize; 
    ll T = 1;
    in >> T;
    while(T--) {
        solve();
    }
    return 0;
}