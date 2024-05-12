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
const ll MAX = 4e5+10;
vector<pair<int,int>> g[MAX];
int pre[MAX];
int low[MAX];
int comp[MAX];
int sz[MAX];
int degree[MAX];
bool usedEdg[MAX];
bool articulation[MAX];
bool usedComp[MAX];
int t = 1;
int c = 1;
stack<int> stc;
int n,a,b;
int caso = 0;

void init(){
    for (int i=0; i<n+10; i++){
        g[i].clear();
        pre[i] = 0;
        low[i] = 0;
        comp[i] = 0;
        sz[i] = 0;
        degree[i] = 0;
        usedEdg[i] = 0;
        articulation[i] = false;
        usedComp[i] = false;
        t = 1;
        c = 1;
    }
}

void dfs(int u){
    pre[u] = low[u] = t++;
    int contfilhos = 0;
    for (auto [v,e]:g[u]) if (!usedEdg[e]){
        usedEdg[e] = true;
        stc.push(e);
        if (!pre[v]){
            contfilhos++;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], pre[v]);
        }

        if (low[v] >= pre[u] and (u != 1 or contfilhos >= 2)){
            articulation[u] = true;
            int atual;
            do{
                atual = stc.top();
                stc.pop();
                comp[atual] = c;
            }while(atual != e);
            c++;
        }

    }
}


void solve(){
    caso++;
    cout << "Case " << caso << ": ";
    init();

    for (int i=1; i<=n; i++){
        cin >> a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        
    }
    dfs(1);

    while (!stc.empty()){
        comp[stc.top()] = c;
        stc.pop();
    }
    c++;



    for (int u = 1; u<=n+3; u++){
        if (g[u].empty()) continue;
        if (articulation[u]){
            for (auto [v,e]:g[u]){
                if (!usedComp[comp[e]]){
                    degree[comp[e]]++;
                }
                usedComp[comp[e]] = true;
            }
            for (auto [v,e]:g[u]){
                usedComp[comp[e]] = false;
            }
        }
        else{
            sz[comp[g[u][0].second]]++;
        }
    }


    if (c == 2){
        cout << 2 << " " << ((ll)sz[1] * (sz[1]-1))/2 << endl;
        return;
    }

    ll resp = 0;
    ll ways = 1;

    for (int i=1; i<c; i++){
        if (sz[i]){
            if (degree[i] == 1){
                resp++;
                ways *= sz[i];
            }
        }
    }

    cout << resp << " " << ways << endl;
}

int main() {
    optimize; 
    ll T = 1;
//    cin >> T;
    while(cin >> n) {
        if (n)solve();
    }
    return 0;
}