#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
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
 
#define f(i,s,e) for(long long int i=s;i<e;i++)
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
#define MOD 998244353
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
void yes() { cout<<"YES\n"; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 1e3+10;
const int MAXM = 1e3+10;
const int K = 12;

int st[K+1][MAXN][K+1][MAXM];
int prefix[MAXN][MAXM];
int tab[MAXN][MAXM];
int n,m;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            st[0][i][0][j] = tab[i][j];
        }
        for (int a=1; (1<<a) <= m; a++){
            for (int b=0; b+(1<<a) <= m; b++){
                st[0][i][a][b] = max(st[0][i][a-1][b], st[0][i][a-1][b + (1<<(a-1))]);
            }
        }
    }

    for (int i=1; (1<<i)<=n; i++){
        for (int j=0; j +(1<<i)<=n; j++){
            for (int a=1; (1<<a)<=m; a++){
                for (int b=0; b+(1<<a)<=m; b++){
                    st[i][j][a][b] = max(st[i-1][j][a][b], st[i-1][j+(1<<(i-1))][a][b]);
                }
            }
        }
    }
}

int getmax(int x1, int y1, int x2, int y2){
    int i = log2_floor(x2-x1+1);
    int j = log2_floor(y2-y1+1);
    int max1 = max(st[i][x1][j][y1], st[i][x2 - (1<<i) + 1][j][y1]);
    int max2 = max(st[i][x1][j][y2 - (1<<j)+1], st[i][x2 - (1<<i) + 1][j][y2 - (1<<j)+1]);
    return max(max1, max2);
}

int getsum(int x1, int y1, int x2, int y2){
    return prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1];
}

void solve(){
    cin >> n >> m;
    n++,m++;
    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            cin >> tab[i][j];
            prefix[i][j] = tab[i][j] +  prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    build();
    int q;
    cin >> q;
    int a,b;

    while (q--){
        cin >> a >> b;
        int resp = INF;
        for (int i=1; i+a-1<n; i++){
            for (int j=1; j+b-1<m; j++){               
                resp = min(resp, a*b*getmax(i,j,i+a-1,j+b-1) - getsum(i,j,i+a-1,j+b-1));
            }
        }
        cout << resp << endl;
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