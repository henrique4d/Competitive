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
#define INFLL 0x3f3f3f3f3f3f3f3fLL
 
#define mod 998244353LL
 
#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }

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
const ll MAXN = 1e3 + 10;
const ll MAXM = 1e3 + 10;
vector<pair<ll,ll>> adj[MAXN];
ll dp[MAXN][MAXM];
ll visited[MAXN][MAXM];

ll speed[MAXN];


void solve(){
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        adj[i].clear();
        for (int j=0; j<1002; j++){
            dp[i][j] = INFLL;
            visited[i][j] = false;
        }
    }

    ll a,b, c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    for (int i=0; i<n; i++){
        cin >> speed[i];
    }
    priority_queue <pair<ll,pair<ll,ll>>> pq;
    pq.push({0,{0,speed[0]}});
    dp[0][speed[0]] = 0;

    ll u, s;
    ll resp = INFLL;
    while (!pq.empty()){
        u = pq.top().second.first;
        s = pq.top().second.second;
        c = pq.top().first;
        pq.pop();
        if (visited[u][s]) continue;
        visited[u][s] = true;

        for (auto v: adj[u]){
            if (dp[v.first][min(s, speed[v.first])] > (c - v.second * s)*-1){
                dp[v.first][min(s, speed[v.first])] = (c - v.second * s)*-1;
                pq.push({c - v.second * s, {v.first, min(s, speed[v.first])}});
                if (v.first == n-1) resp = min((c - v.second * s)*-1, resp);
            }
        }
    }
    cout << resp << endl;
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