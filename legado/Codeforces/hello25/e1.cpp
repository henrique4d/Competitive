#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

typedef int ll;
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
const ll MAXN = 500;
vector<pair<ll,ll>> g[MAXN];
ll n,m,k,q;
ll visited[MAXN];
ll save[MAXN][MAXN][MAXN];

bool eval(int comeco, int fim, int x){
    deque<pair<ll,ll>> pq;
    for (int i=0; i<n+10; i++){
        visited[i] = false;
    }
    pq.push_back({k,comeco});
    
    while (!pq.empty()){
        ll pos = pq.front().second;
        ll vida = pq.front().first;
        pq.pop_front();
        if (vida == -1) continue;
        if (visited[pos]) continue;

        visited[pos] = true;
        
        if (pos == fim) return true;
        // cout << "visitando " <<  pos << endl;
 
        for (auto [v,w]:g[pos]){
            if (!visited[v]){
                if (w > x) pq.push_back({vida - (w>x), v});
                else pq.push_front({vida - (w>x), v});
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m >> q;
    for (int i=0; i<n+10; i++){
        g[i].clear();
    }
    // cout << n << " " << m << " " << q << endl;
    int u,v,w;
    vector<ll> pesos;
    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        pesos.push_back(w);
    }
    sort(all(pesos));
    // cout << eval(2,2,2) << endl;
    // exit(0);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            for (int k=0; k<pesos.size(); k++){
                // cout << i<< " " << j << " " << k << endl;
                // cout << eval(i,j,pesos[k]) << endl;
                save[i][j][k] = eval(i,j,pesos[k]);
            }
        }
    }

    while (q--){
        cin >> u >> v >> k;
        k--;
        ll l = 0;
        ll r = m;
        // cout << eval(u,v,1000) << endl;
        // exit(0);
        while (r-l > 1){
            // cout << l << " " << r << endl;
            m = l + (r-l)/2;
            if (save[u][v][m]) r = m;
            else l = m;  
        }
        cout << pesos[r] << " ";
        // exit(0);
    }
    cout << endl;
    
}

int main() {
    // optimize;
    ll T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}