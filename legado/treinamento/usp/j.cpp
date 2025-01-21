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
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << bitset<10>(x) << ","; cout << "\b}\n"; }
#define MOD 998244353
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 5e5 + 10;
bool imp[MAXN];
bool visited[MAXN];
bool respondidos[MAXN];
int dad[MAXN];
map<pair<int,int>, int> cont1;

int contachados = 0;
vector<int> adj[MAXN];


int dfs(int v, int p, int gamb){
    if (visited[v]) return 0;
    //cout << "chamando dfs para " << v << endl;
    visited[v] = true;
    int cont = 0;
    if (imp[v]){
        contachados++;
        cont = 1;
    }
    for (auto u:adj[v]){
        cont += dfs(u, v, gamb);
    }
    cont1[{p,v}] = cont+gamb;
    cont1[{v,p}] = cont+gamb;
    //cout << "colocando o cont na posicao " << p << " " << v << " como " << cont << endl;

    return cont;
}

void solve(){
    int n,m;
    cin >> n >> m;
    int a,b;
    vector<pair<int,int>> arestas;

    for (int i=0; i<n; i++){
        cin >> a >> b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        arestas.push_back({a,b});
    }
    int aux;
    for (int i=0; i<m; i++){
        cin >> aux;
        imp[i] = aux%2;
    }
    
    
    for (int i=0; i<m; i++){
        if (!visited[i]){
            contachados = 0;
            if (imp[i]) dfs(i,-1,0);
        }
        else dfs(1,-1,1);
        
        if (contachados%2){
            cout << -1 << endl;
            return;
        }
    }
    vector<int> resp;
    for (int i=0; i<n; i++){
        if (cont1[arestas[i]]%2) resp.push_back(i+1);
    }
    cout << resp.size() << endl;
    for (int i=0; i<resp.size(); i++){
        if (i) cout << " ";
        cout << resp[i];
    }
    cout << endl;
}

int main() {
    optimize;
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}