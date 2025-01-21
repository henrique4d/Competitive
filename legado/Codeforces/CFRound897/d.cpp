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
#define MOD 998244353
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
const ll MAXN = 2e5+10;
ll a[MAXN];
ll visited[MAXN];
ll c[MAXN];
bool b[MAXN];
bool visited2[MAXN];


ll dfs(int pos, int time){
    // cout << "chamando dfs " << pos << " " << time << " " << a[pos] << endl;
    visited[pos] = time;
    int next = a[pos];
    if (visited[next]) return c[pos] =  time - visited[next];
    return c[pos] = 1 + dfs(a[pos], time+1);
}

int n,k;

bool dfs2(int pos){
    // cout << "chamando dfs2 " << pos << " " << c[pos] << endl;
    visited2[pos] = true;
    int next = a[pos];
    if (visited2[next]){
        return b[pos] = c[pos] == k-1;
    }
    return b[pos] = dfs2(a[pos]);
}

void solve(){
    
    cin >> n >> k;
    if (k == 1){
        for (int i=1; i<=n; i++){
            cin >> a[i];
            if (a[i] != i){
                no();
                return;
            }
        }
        yes();
        return;
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
        visited[i] = 0;
        c[i] = 0;
        b[i] = false;
        visited2[i] = false;
    }
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dfs(i, 1);
            dfs2(i);
        }
    }
    // cout << "o k vale " << k << endl;
    // for (int i=1; i<=n; i++){
    //     // if (c[i] < k){
    //     //     no();
    //     //     return;
    //     // }
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    // for (int i=1; i<=n; i++){
    //     // if (c[i] < k){
    //     //     no();
    //     //     return;
    //     // }
    //     cout << b[i] << " ";
    // }
    for (int i=1; i<=k; i++){
        if (!b[i]){
            no();
            return;
        }
    }
    yes();
    //cout << endl;

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