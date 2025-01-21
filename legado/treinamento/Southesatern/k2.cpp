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
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
// string to_upper(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
// string to_lower(string a) { for (long long ll i=0;i<(long long ll)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
// void yes() { cout<<"Yes\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"No\n"; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 2e5+10;
vector<ll> neighbors[MAXN];
int degree[MAXN];
int leaf[MAXN];
vector<ll> resp;
bool two = false;
int set_leafs(int u, int p){
    //cout << "chamando a funcao para " << u << " " << p << endl;
    int menor = INT_MAX;
    for (auto v:neighbors[u]){
        if (v == p) continue;
        menor = min(menor, set_leafs(v, u));
    }
    if (menor == INT_MAX) menor = u;
    leaf[u] = menor;
    //cout << "terminou" << endl;
    return menor;
}

void dfs2(int u, int p){
    cout << "chamando dfs2 " << u << endl;
    
    vector<pair<int,int>> next;
    for (auto v:neighbors[u]){
        if (u == p ) continue;

        if (leaf[v] != INT_MAX) next.push_back({leaf[v],v});
    }
    sort(all(next));
    for (int i=0; i<next.size(); i++){
        cout << next[i].first << "-" << next[i].second << "  ";
    }
    cout << endl;
    cout << next << endl;
    for (auto v:next){
        dfs2(v.second,u);
    }
    resp.push_back(u);
}

void dfs(int u, int p){
    cout << "chamando dfs " << u << endl; 

    vector<pair<int,int>> next;
    for (auto v:neighbors[u]){
        if (v == p ) continue;
        if (leaf[v] != INT_MAX) next.push_back({leaf[v],v});
    }
    sort(all(next));
    resp.push_back(u);
    for (int i=0; i<next.size(); i++){
        cout << next[i].first << "-" << next[i].second << "  ";
    }
    cout << endl;
    cout << next << endl;
    for (auto v:next){
        dfs(v.second,u);
    }

}




void solve(){
    int n;
    cin >> n;
    resp.clear();
    for (int i=0; i<n; i++){
        degree[i] = 0;
        neighbors[i].clear();
    }
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        u--, v--;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for (int i=0; i<n; i++){
        if (degree[i] == 1){
            set_leafs(i, -1);
            dfs(i,-1);
            break;
        }
    }
    for(int i=0; i<resp.size(); i++){
        cout << resp[i] << " ";
    }
    cout << endl;

}



int main() {
    //optimize;
    ll T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}