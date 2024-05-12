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
ll a[MAXN];
vector<ll> g[MAXN];
ll secondFarthest[MAXN];
ll proximo[MAXN];
ll anterior[MAXN];
ll leftt[MAXN];
ll rigtht[MAXN];

ll n;


pair<ll,ll> farthest(ll u, ll p, ll d, bool path = false, ll proib = -1){
    ll index = u;
    ll dist = 0;
    ll second = 0;
    
    for (auto v:g[u]) if (v!=p and v!=proib){
        auto [ind,w] = farthest(v, u,0, path, proib);

        if (w > second){
            second = w;
        }        
        if (w > dist){
            second = dist;
            dist = w;
            index = ind;
            if (path){
                proximo[u] = v;
                anterior[v] = u;
            }
        }

    }
    if (path){
        secondFarthest[u] = second;
    }

    return {index, dist + a[u]};
}

void solve(){
    ll u,v;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    for (int i=1; i<n; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    auto [d1,_] = farthest(1, 0, 0);
    auto [d2, diametro] = farthest(d1,0,0,true);

    ll best_sub = 0;
    int atual = d1;
    ll l = 0;
    ll r = diametro;

    ll daux1;
    ll daux2;
    ll diametroaux = 0;

    do{
        l += a[atual];
        leftt[atual] = l + secondFarthest[atual];
        rigtht[atual] = r + secondFarthest[atual];
        r -= a[atual];
        for (auto v:g[atual]){
            if (v != proximo[atual] and v!= anterior[atual]){
                daux1 = farthest(v,0,0,false,atual).first;
                diametroaux = farthest(daux1, 0,0,false,atual).second;
                
                best_sub = max(best_sub, diametroaux);
                
            }
        }
        atual = proximo[atual];

    }while(atual!=d2);

    atual = d1;
    do{
        leftt[atual] = max(leftt[atual], leftt[anterior[atual]]);
        atual = proximo[atual];
    }while(atual!=d2);

    atual = d2;
    do{
        rigtht[atual] = max(rigtht[atual], rigtht[proximo[atual]]);
        atual = anterior[atual];
    }while(atual!=d1);

    ll resp = diametro + best_sub;
    
    atual = d1;
    do{
        resp = max(resp, leftt[atual] + rigtht[proximo[atual]]);
        atual = proximo[atual];
    }while(atual!=d2);

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