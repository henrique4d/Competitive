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
const int MAXN = 3000+10;
map<pair<int,int>,set<int>> val;
vector<int> g[MAXN];
map<pair<int,int>,bool> visited;
map<pair<int,int>, pair<int,int>> pai;
int n,m,k,a,b,c;

void solve(){
    cin >> n >> m >> k;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0; i<k; i++){
        cin >> a >> b >> c;
        val[{a,b}].insert(1+3*i);
        val[{b,c}].insert(2+3*i);
    }
    queue<pair<int,int>> q;

    q.push({1,0});
    visited[{1,0}] = true;
    int final = -1;
    while (!q.empty()){
        auto u = q.front().first;
        int w = q.front().second;
        cout << "avaliando " <<  u << " " << w << endl;
        q.pop();
        bool chegou = false;
        bool continuar = true;
        // for (auto v:g[u]) for(auto estado:val[{u,v}]) if (!(!visited[{v,estado}] and (w%3 != 1 or estado %3 != 2 or w+1 != estado))) continuar = false;
        // if (!continuar) continue;

        for (auto v:g[u]) for(auto estado:val[{u,v}]) if (!visited[{v,estado}] and (w%3 != 1 or estado %3 != 2 or w+1 != estado) ){
            q.push({v,estado});
            visited[{v,estado}] = true;
            pai[{v,estado}] = {u,w};
            cout << "adicionando na fila " << v << " " << estado << endl;
            if (v == n){
                chegou = true;
                final = estado;
                cout << "encontrou o final " << endl;
                break;
            };
        }
        if (chegou) break;
    }
    vector<int> resp;
    if (final == -1){
        cout << -1 << endl;
        return;
    }
    

    pair<int,int> atual = {n,final};
    while(atual.first != 0){
        resp.push_back(atual.first);
        atual = pai[{atual.first,atual.second}];
    }
    reverse(all(resp));
    cout << resp.size()-1 << endl;
    for (auto x:resp){
        cout << x << " ";
    }
    cout << endl;
    return;



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