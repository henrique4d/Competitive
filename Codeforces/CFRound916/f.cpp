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
const ll MAXN = 2e5 + 10;

ll deep[MAXN];
ll grau[MAXN];
ll pai[MAXN];
vector<ll> filhos[MAXN];


void dfs(int u, int profundidade, int p){
    deep[u] = profundidade;
    pai[u] = p;
    for (auto v:filhos[u]){
        grau[u]++;
        dfs(v, profundidade+1, u);
    }
}

void solve(){
    int n;
    cin >> n;
    ll father;
    deep[0] = 0;
    grau[0] = 0;
    pai[0] = 0;
    filhos[0].clear();
    for (int i=0; i<n; i++){
        filhos[i].clear();
    }

    for (int i=1; i<n; i++){
        cin >> father;
        father--;
        deep[i] = 0;
        grau[i] = 0;
        pai[i] = 0;
        filhos[father].push_back(i);
    }
    
    dfs(0, 0, -1);


    set<ll> leaf;
    priority_queue<pair<ll,ll>> pq;
    

    for (int i=0; i<n; i++){
        // cout << i << " " << grau[i] << endl;
        if (!grau[i]){
            leaf.insert(i);
            pq.push({deep[i], i});
        }
    }
    
    ll resp = 0;
    while(leaf.size() > 1){
        auto u = pq.top();
        pq.pop();
        auto v = pq.top();
        pq.pop();
        resp++;
        // cout << "removendo os vertices " << u.second << " " << v.second << endl;
        leaf.erase(u.second);
        leaf.erase(v.second);
        
        grau[pai[u.second]]--;

        if (!grau[pai[u.second]]){
            leaf.insert(pai[u.second]);
            pq.push({deep[pai[u.second]], pai[u.second]});
        }

        grau[pai[v.second]]--;
        if (!grau[pai[v.second]]){
            leaf.insert(pai[v.second]);
            pq.push({deep[pai[v.second]], pai[v.second]});
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