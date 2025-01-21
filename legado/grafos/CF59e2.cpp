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
const int MAXM = 4e4+10;
const int MAXN = 3000+10;
vector<pair<int,int>> g[MAXM];
vector<int> ge[MAXM];
pair<int,int> edge[MAXM];
int incide[MAXN][MAXN];
set<pair<int,int>> forb;
int visited[MAXM][2];
pair<int,int> pai[MAXM][2];

int n,m,k,a,b,c;

void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=m; i++){
        cin >> a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
        edge[i] = {a,b};
        incide[a][b] = i;
        incide[b][a] = i;
    }
    for (int i=1; i<=m; i++){
        for (auto [v,e]:g[edge[i].first]){
            if (e != i){
                ge[i].push_back(e);
            }
        }
        for (auto [v,e]:g[edge[i].second]){
            if (e != i){
                ge[i].push_back(e);
            }
        }
    }
    for (int i=0; i<k; i++){
        cin >> a >> b >> c;
        forb.insert({incide[a][b], incide[b][c]});
    }

    queue<pair<int,int>> q;
    for (auto [v,e]:g[1]){
        if (edge[e].first == 1){
            q.push({e,1});
            visited[e][1] = true;
            pai[e][1] = {0,0};
        }
        else{
            q.push({e,0});
            visited[e][0] = true;
            pai[e][0] = {0,0};
        }
    }

    int e;
    int d;
    while (!q.empty()){
        e = q.front().first;
        d = q.front().second;
        q.pop();
        if (edge[e].first == n or edge[e].second == n) break;
        for (auto neigh:ge[e]) {
            bool dir;
            if (d and edge[e].second == edge[neigh].first) dir = 1;
            else if (d and edge[e].second == edge[neigh].second) dir = 0;
            else if (!d and edge[e].first == edge[neigh].first) dir = 1;
            else if (!d and edge[e].first == edge[neigh].second) dir = 0;
            else continue;
            if (visited[neigh][dir] or forb.find({e,neigh}) != forb.end()) continue;
            visited[neigh][dir] = true;
            pai[neigh][dir] = {e,d};
            q.push({neigh,dir});
        }
        if (!visited[e][!d]){
            visited[e][!d] = true;
            pai[e][!d] = {e,d};
            q.push({e,!d});
        }
    }

    if (edge[e].first != n and edge[e].second != n){
        cout << -1 << endl;
        return;
    }
    
    vector<int> resp;
    resp.push_back(n);
    int lastV = n;
    int edgeAtual = e;
    int dirAtual = d;

    while (edgeAtual != 0){
        if (dirAtual == 1) resp.push_back(edge[edgeAtual].first);
        else resp.push_back(edge[edgeAtual].second);
        auto aux = pai[edgeAtual][dirAtual];
        edgeAtual = aux.first;
        dirAtual = aux.second;
    }
    
    reverse(all(resp));

    cout << resp.size()-1 << endl;
    for (auto x:resp){
        cout << x << " ";
    }
    cout << endl;
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