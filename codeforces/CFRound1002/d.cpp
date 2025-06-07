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
const ll MAXN = 2000;
vector<ll> g[MAXN];
vector<ll> g2[MAXN];
ll n, start1, start2, m;
ll dist1[2][MAXN];
ll dist2[2][MAXN];
bool compativel[MAXN];

void init(){
    for (int i=0; i<n+10; i++){
        g[i].clear();
        g2[i].clear();
        dist1[0][i] = INFLL;
        dist1[1][i] = INFLL;
        dist2[0][i] = INFLL;
        dist2[1][i] = INFLL;
        compativel[i] = false;
        
    }
}

void solve(){
    cin >> n >> start1 >> start2 >> m;
    int u,v;
    init();
    set<pair<ll,ll>> s;

    for (int i=0; i<m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        s.insert({u,v});
        s.insert({v,u});

    }
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
        if (s.find({u,v}) != s.end()){
            compativel[u] = true;
            compativel[v] = true;
        }
    }


    priority_queue <pair<pair<ll,ll>,ll>> pq;
    //dist1[0][start1] = 0;
    pq.push({{0,start1},0});
    while(!pq.empty()){
        ll u = pq.top().first.second;
        ll w = -pq.top().first.first;
        ll paridade = pq.top().second;
        pq.pop();

        if (dist1[paridade][u] != INFLL) continue;
        dist1[paridade][u] = w;

        for (auto v:g[u]){
            ll newW = w + abs(v-u);
            if (dist1[!paridade][v] == INFLL) pq.push({{-newW, v}, !paridade});
        }
    }


    pq.push({{0,start2},0});
    while(!pq.empty()){
        ll u = pq.top().first.second;
        ll w = -pq.top().first.first;
        ll paridade = pq.top().second;
        pq.pop();

        if (dist2[paridade][u] != INFLL) continue;
        dist2[paridade][u] = w;

        for (auto v:g2[u]){
            ll newW = w + abs(v-u);
            if (dist2[!paridade][v] == INFLL) pq.push({{-newW, v}, !paridade});
        }
    }

    ll ans = INFLL;
    for (int i=0; i<n; i++){  
        cout << i << " " << compativel[i] << " " << dist1[0][i] << " " << dist2[0][i] << endl;
        if (!compativel[i]) continue;
        ans = min(ans, dist1[0][i] + dist2[0][i]);
        ans = min(ans, dist1[1][i] + dist2[1][i]);
    }
    cout << ans << endl;

}

int main() {
    optimize;
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}