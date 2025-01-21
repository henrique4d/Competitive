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

#define mod 1000000007LL

#define f(i,s,e) for(long long ll i=s;i<e;i++)
template <class T>
void prll_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
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
const ll MAXN = 600;
vector<ll> C;
vector<ll> R;
vector<ll> FC;
vector<ll> FR;
vector<vector<ll>> CR;
vector<vector<char>> a;
vector<vector<bool>> visited;
ll n,m;
int minR,minC,maxR,maxC;
ll sz;

void init(){
    R.resize(n+20);
    FR.resize(n+20);
    C.resize(m+20);
    FC.resize(m+20);
    CR.resize(0);
    CR.resize(n+20, vector<ll>(m+20));
    a.resize(0);
    a.resize(n+20, vector<char>(m+20));
    visited.resize(0);
    visited.resize(n+20, vector<bool>(m+20));
    
    for (int i=0; i<n+10; i++){
        R[i] = 0;
        FR[i] = 0;
    }
    for (int i=0; i<m+10; i++){
        C[i] = 0;
        FC[i] = 0;
    }
    for (int i=0; i<n+10; i++){
        for (int j=0; j<m+10; j++){
            CR[i][j] = 0;
            a[i][j] = '.';
            visited[i][j] = false;
        }
    }

}

void dfs(int i, int j){
    if (a[i][j] == '.' or visited[i][j]) return;
    visited[i][j] = true;
    sz++;
    minR = min(minR, i);
    maxR = max(maxR, i);
    minC = min(minC, j);
    maxC = max(maxC, j);

    int di = 0;
    int dj = -1;
    int aux = 4;
    while (aux--){
        dfs(i+di, j+dj);
        swap(di,dj);
        dj*=-1;
    }
}

void solve(){
    cin >> n >> m;
    init();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (a[i][j] == '.'){
                FR[i]++;
                FC[j]++;
            }
            else if (!visited[i][j]){
                sz = 0;
                minR = INF;
                minC = INF;
                maxR = -1;
                maxC = -1;                
                dfs(i,j);
                minC--,minR--,maxR++,maxC++;

                C[minC] += sz;
                C[maxC+1] -= sz;
                R[minR] += sz;
                R[maxR+1] -= sz;

                CR[minR][minC] += sz;
                CR[maxR+1][minC] -= sz;

                CR[minR][maxC+1] -= sz;

                CR[maxR+1][maxC+1] += sz;
            }
        }
    }
    for (int i=1; i<=n; i++){
        R[i] += R[i-1];
        CR[i][0] += CR[i-1][0];
    }
    for (int i=1; i<=m; i++){
        C[i] += C[i-1];
        CR[0][i] += CR[0][i-1];
    
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            CR[i][j] += CR[i-1][j] + CR[i][j-1] - CR[i-1][j-1];
        }
    }

    ll resp = 0;

    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            resp = max(resp, FR[i] + FC[j] - (a[i][j] == '.') + R[i] + C[j] - CR[i][j]);
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