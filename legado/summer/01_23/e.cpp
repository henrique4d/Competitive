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

const ll MAXN = 2e3;
char tab[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool visited2[MAXN][MAXN];
ll resp[MAXN][MAXN];
int n,m,k;

ll dfs(int i, int j){
    visited[i][j] = true;
    int dx = -1, dy = 0;
    int cont = 0;
    for (int mov=0; mov<4; mov++){
        if (tab[i+dx][j+dy] == '*'){
            cont++;
        }
        else if (!visited[i+dx][j+dy]){
            cont += dfs(i+dx, j+dy);
        }
        swap(dx, dy);
        dy*=-1;
    }
    return resp[i][j] = cont;
}

void dfs2(int i, int j, int val){
    visited2[i][j] = true;
    resp[i][j] = val;
    int dx = -1, dy = 0;
    int cont = 0;
    for (int mov=0; mov<4; mov++){
        
        if (tab[i+dx][j+dy] == '*'){
        }
        else if (!visited2[i+dx][j+dy]){
            dfs2(i+dx, j+dy, val);
        }
        swap(dx, dy);
        dy*=-1;
    }
}


void solve(){
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> tab[i][j];
        }
    }
    int u,v;
    for (int i=0; i<k; i++){
        cin >> u >> v;
        if (resp[u][v]){
            cout << resp[u][v] << endl;
            continue;
        }
        int x = dfs(u,v);
        cout << x << endl;
        dfs2(u,v,x);        
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