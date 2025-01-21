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

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 1000000007LL
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
const ll MAXK = 26;
vector<pair<ll,ll>> g[MAXN];
pair<ll,ll> pai[MAXK][MAXN];
ll depth[MAXN];
bool inmst[MAXN];
vector<pair<pair<ll,ll>,ll>> queries;
ll n,m;

ll binary_lifting(int a, int b){
    ll ans = 0;
    if (depth[a] < depth[b]) swap(a,b);
    for (int k=25; k>=0; k--){
        if (depth[a] - (1<<k) >= depth[b]){
            ans = max(ans, pai[k][a].second);
            a = pai[k][a].first;
        }
    }
    for (int k=25; k>=0; k--){
        if (pai[k][a].first != pai[k][b].first){
            ans = max(ans, pai[k][a].second);
            a = pai[k][a].first;
            
            ans = max(ans, pai[k][b].second);
            b = pai[k][b].first;
        }
    }
    if (a != b) ans = max({ans, pai[0][a].second, pai[0][b].second});
    return ans;
}

void solve(){
    cin >> n >> m;
    ll u,v,w;
    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        queries.push_back({{u,v},w});
    }
    priority_queue<pair<ll,pair<ll,ll>>> pq;
    pq.push({0,{0,0}});
    ll mstValue = 0;
    while (!pq.empty ()){
        w = -pq.top().first;
        v = pq.top().second.first;
        u = pq.top().second.second;
        pq.pop();
        if (!inmst[v]){
            inmst[v] = true;
            pai[0][v] = {u,w};
            depth[v] = depth[u]+1;
            mstValue += w;
            for (auto [nextVertice,weigth]:g[v]) if (!inmst[nextVertice]){
                pq.push({-weigth,{nextVertice,v}});
            }
        }
    }
    for (int k=1; k<MAXK; k++){
        for (int i=0; i<n; i++){
            pai[k][i].first = pai[k-1][pai[k-1][i].first].first;
            pai[k][i].second = max(pai[k-1][i].second,pai[k-1][pai[k-1][i].first].second );
        }
    }
    for (int i=0; i<m; i++){
        u = queries[i].first.first;
        v = queries[i].first.second;
        w = queries[i].second;
        cout << mstValue + w - binary_lifting(u,v) << endl;
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