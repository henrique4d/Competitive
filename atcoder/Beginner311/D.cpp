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
const int MAXN = 220;
bool mapa[MAXN][MAXN];
bool visited[MAXN][MAXN][3][3];
bool used[MAXN][MAXN];


void dfs(int i, int j, int vi, int vj){
    //cout << "chamando dfs na posicao i " << i << " j " << j << " com velocidade " << vi << " " << vj << endl;
    if (visited[i][j][vi+1][vj+1]) return;
    visited[i][j][vi+1][vj+1] = true;
    used[i][j] = true;
    
    if (!mapa[i + vi][j + vj]){
        if (vi != 1) dfs(i, j, 1,0);
        if (vi != -1) dfs(i, j, -1,0);
        if (vj != 1) dfs(i, j, 0,1);
        if (vj != -1) dfs(i, j, 0,-1);
        return;
    }
    //cout << "here\n";

    dfs(i+vi, j+vj, vi, vj);
}

void solve(){
    int n,m;
    cin >> n >> m;
    char aux;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> aux;
            if (aux == '.') mapa[i][j] = true;
            else mapa[i][j] = false;
            for (int k=0; k<3; k++){
                visited[i][j][0][k] = false;
                visited[i][j][1][k] = false;
                visited[i][j][2][k] = false;
            }
            used[i][j] = false;
        
        }
    }
    dfs(1,1, 1,0);
    dfs(1,1, -1,0);
    dfs(1,1, 0,1);
    dfs(1,1, 0,-1);
    
    int cont = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //cout << mapa[i][j] << " ";
            cont += used[i][j];
        }
        //cout << endl;
    }
    cout << cont << endl;

}
 
 
 
int main() {
    optimize;
    ll T = 1;
//    cin >> T;
 
    while(T--) {
        solve();
    }
 
    return 0;
}