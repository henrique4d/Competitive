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
const ll MAXN = 2e5+10;
vector<pair<ll,ll>> g[MAXN];
ll proximo[MAXN];
ll peso[MAXN];
ll sub[MAXN];
ll n,k,a,b,c;

pair<ll,ll> farthest(int u, int d, int p){
    ll maior_dist = 0;
    ll resp = u;
    for (auto [v,w]: g[u]) if (v!=p){
        auto aux = farthest(v, d+w, u);
        if (aux.second+w > maior_dist){
            maior_dist = aux.second+w;
            resp = aux.first;
            proximo[u] = v;
            peso[u] = w;
        }
    }
    return {resp, maior_dist};
}

pair<ll,ll> farthest2(int u, int d, int p, int prox){
    ll maior_dist = 0;
    ll resp = u;

    for (auto [v,w]: g[u]) if (v!=p and v!=prox){
        auto aux = farthest2(v, d+w, u, prox);
        if (aux.second+w > maior_dist){
            maior_dist = aux.second+w;
            resp = aux.first;
            sub[u] = maior_dist;
        }
    }
    return {resp, maior_dist};
}


void solve(){
    cin >> n >> k;
    for (int i=0; i<n-1; i++){
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    ll distancia1 = 0;
    auto [d1,qwer] = farthest(1,0,0);
    auto [d2,distancia2] = farthest(d1,0,0);

    int atual = d1;
    int prev = 0;
    multiset<ll> s;

    queue<ll> path;
    ll resp = INFLL;
    do{
        farthest2(atual,0,prev, proximo[atual]);
        path.push(atual);
        s.insert(sub[atual]);
        distancia2-= peso[prev];
        if (path.size() > k){
            s.erase(s.find(sub[path.front()]));
            distancia1 += peso[path.front()];
            path.pop();
        }
        resp = min(resp, max({*s.rbegin(), distancia1,distancia2}));
        prev = atual;
        atual = proximo[atual];
    }while(prev != d2);

    cout << resp << endl;
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