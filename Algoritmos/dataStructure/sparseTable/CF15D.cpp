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
const int MAXN = 1005;
const int MAXM = 1005;
const int K = 9;

ll prefix[MAXN][MAXM];
int tab[MAXN][MAXM];
int st[K+1][MAXN][MAXM];
bool done[MAXN][MAXM];
 
int n,m,a,b;
 
void build(){
    for (int col =0; col<m; col++){
        for (int i=0; i<n; i++){
            st[0][i][col] = tab[i][col];
        }
        for (int i=1; (1<<i) <= n; i++){
            for (int j=0; j + (1<<i) <=n; j++){
                st[i][j][col] = min(st[i-1][j][col], st[i-1][j + (1<<(i-1))][col]);       
            }
        }
    }
}
 
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
 
int getMin(int x1, int y1, int x2, int y2){
    int i = log2_floor(x2-x1 + 1);
    return min(st[i][x1][y1], st[i][x2 - (1<<i)+1][y1]);
}
 
ll getSoma(int x1, int y1, int x2, int y2){
    return prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1];
}
 
void solve(){
    cin >> n >> m >> a >> b;
    n++;
    m++;
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            cin >> tab[i][j];
            prefix[i][j] = (ll)tab[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    build();
    priority_queue<pair<ll, pair<int,int>>> pq;
    vector<pair<ll,pair<int,int>>> resp;
 
    multiset<int> mults;

    for (int i=1; i+a-1<n; i++){
        mults.clear();
        
        for (int j=1; j<=b; j++){
            mults.insert(getMin(i,j,i+a-1, j+b-1));
        }

        for (int j=1; j+b-1<m; j++){
            pq.push({ (ll)a*b*(ll)(*mults.begin())-getSoma(i,j,i+a-1,j+b-1), {-i,-j}});
            mults.erase(mults.find(getMin(i,j,i+a-1, j+b-1)));
            mults.insert(getMin(i,j+b,i+a-1, j+b-1));
        }
    }

    while (!pq.empty()){
        auto atual = pq.top();
        ll w = -atual.first;
        int i = -atual.second.first;
        int j = -atual.second.second;
        pq.pop();
        if (done[i][j]) continue;
        resp.push_back({w, {i,j}});
        for (int u=max(i-a+1,0); u<=i+a-1; u++){
            for (int v=max(j-b+1,0); v<=j+b-1;v++){
                done[u][v] = true;
            }
        }
    }
    cout << resp.size() << endl;
    for (int i=0; i<resp.size(); i++){
        cout << resp[i].second.first << " " << resp[i].second.second << " " << resp[i].first << endl;
    }
}
 
int main() {
    optimize; 
    ll T = 1;
    //cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}