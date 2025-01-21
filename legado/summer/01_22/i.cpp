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
const int MAXN = 2e5+10;
vector<int> g[MAXN];
vector<int> boom[MAXN];
ll visited[MAXN];
ll t = 1;
int n,m,a,b;
void dfs(int u, int p){
    visited[u] = t++;
    for (auto v:g[u]) if (v!=p){
        if (!visited[v]){
            dfs(v, u);
            if (boom[v].size()&1) boom[v].push_back(u);
            else boom[u].push_back(v);
        }
        else if (visited[v] < visited[u]){
            boom[v].push_back(u);
        }
    }
}


void solve(){
    cin >> n >> m;
    vector<tuple<int,int,int>> resp;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]) dfs(i,-1);
    }

    for (int i=1; i<=n; i++){
        for (int j=0; j<(int)boom[i].size()-1; j+=2){
            resp.push_back(make_tuple(boom[i][j], i, boom[i][j+1]));
        }
    }
    cout << resp.size() << endl;
    for (auto boomerang:resp){
        cout << get<0>(boomerang) << " " << get<1>(boomerang) << " " << get<2>(boomerang) << endl;
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