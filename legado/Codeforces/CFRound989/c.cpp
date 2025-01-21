#include<bits/stdc++.h>
using namespace std;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
 
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define endl "\n"
 
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
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void no() { cout<<"NO\n"; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */ 

vector<vector<char>> a;
vector<vector<char>> final;
ll n,m;

ll cont = 0;

char dfs(int i, int j){
    if (i == 0 or j == 0 or i == n+1 or j == m+1) return '.';
    // cout << i << " " << j << " " << a[i][j] << endl;
    
    if (final[i][j] != '*') return final[i][j];


    // cout << "visitando " << i << " " << j << endl;

    if (a[i][j] == '.' or a[i][j] == '?' or final[i][j] == 'P') return final[i][j] = a[i][j];
    final[i][j] = 'P';

    if (a[i][j] == 'U') return final[i][j] = dfs(i-1,j);
    else if (a[i][j] == 'D') return final[i][j] = dfs(i+1,j);
    else if (a[i][j] == 'L') return final[i][j] = dfs(i,j-1);
    else if (a[i][j] == 'R') return final[i][j] = dfs(i,j+1);

    return '.';
}

char dfs2(int i, int j){
    if (i == 0 or j == 0 or i == n+1 or j == m+1) return '.';

    if (a[i][j] == '.') return '.';
    if (final[i][j] != '*') return final[i][j];

    final[i][j] = 'O';
    if (final[i-1][j] == '*') dfs2(i-1,j);
    if (final[i+1][j] == '*') dfs2(i+1,j);
    if (final[i][j-1] == '*') dfs2(i,j-1);
    if (final[i][j+1] == '*') dfs2(i,j+1);

    
    if (a[i-1][j] != '.' and (final[i-1][j] == '?' or final[i-1][j] == 'O' or final[i-1][j] == 'P')) final[i][j] = '?';
    if (a[i+1][j] != '.' and (final[i+1][j] == '?' or final[i+1][j] == 'O' or final[i+1][j] == 'P')) final[i][j] = '?';
    if (a[i][j-1] != '.' and (final[i][j-1] == '?' or final[i][j-1] == 'O' or final[i][j-1] == 'P')) final[i][j] = '?';
    if (a[i][j+1] != '.' and (final[i][j+1] == '?' or final[i][j+1] == 'O' or final[i][j+1] == 'P')) final[i][j] = '?';

    return final[i][j];
}

void solve(){

    cin >> n >> m;

    // if (n == 1 or m == 1){
    //     cout << max(n,m) << endl;
    //     return;
    // }
    a.assign(n+10, vector<char>(m+10,'.'));
    final.assign(n+10, vector<char>(m+10,'*'));


    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    if (n == 1 and m == 1){
        cout << 0 << endl;
        return;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (final[i][j] == '*' and a[i][j] != '?') dfs(i,j);
            // if (a[i][j] != '?') dfs(i,j);
        }
    }
    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=m; j++){
    //         cout << final[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (final[i][j] == '*') dfs2(i,j);
            // if (a[i][j] != '?') dfs(i,j);
        }
    }
    ll ans = 0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // cout << final[i][j] << " ";
            if (final[i][j] == '?' or final[i][j] == 'P') ans++;
            // ans += final[i][j] == '?';
        }
        // cout << endl;
    }
    cout << ans << endl;

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