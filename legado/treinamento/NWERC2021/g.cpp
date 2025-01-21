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

/* -------------------------------- Solution starts below -------------------------------- */ 
const int MAXN = 5e3 + 10;
string a[MAXN];
int sz[MAXN];
int dp[MAXN];
int quebra[MAXN];
int szresp[MAXN];
int n,w;
vector<int> resp[MAXN];

int DP(int pos, int maxrow){
    if (dp[pos] != -1) return dp[pos];
    if (pos == n-1) return dp[pos] = sz[pos];
    int best = INF;
    int maiorsize = sz[pos];
    int bestQuebra = -1;
    for (int i=1; i<=maxrow and pos+i < n; i++){
        int val = maiorsize + DP(pos+i, maxrow)+1;
        if (val < best){
            best = val;
            bestQuebra = pos+i;
        }
        maiorsize = max(maiorsize, sz[pos+i]);
    }
    if (pos + maxrow >= n){
        if (maiorsize < best){
            best = maiorsize;
            bestQuebra = -1;
        }
    }
    if (bestQuebra != -1) quebra[pos] = bestQuebra;
    return dp[pos] = best;
}

void init(){
    for (int i=0; i<n+10; i++){
        dp[i] = -1;
        quebra[i] = false;
    }
}

bool eval(int x){
    init();
    return DP(0,x) <= w;
}


void solve(){
    cin >> n >> w;
    for (int i=0; i<n; i++){
        cin >> a[i];
        sz[i] = a[i].size();
    }
    int l = 0;
    int r = n+5;
    int m;

    while (r-l > 1){
        m = l + (r-l)/2;
        if (eval(m)) r = m;
        else l = m;
    }
    eval(r);
    
    int colum = 0;
    int maiorSize = 0;
    
    int aux = 0;
    int proxima_quebra = quebra[0];
    if (!proxima_quebra) proxima_quebra = n;
    for (int i=0; i<=n; i++){
        if (i == proxima_quebra){
            while(aux < r){
                resp[aux].push_back(-1);
                aux++;
            }
            szresp[colum] = maiorSize;
            colum++;
            maiorSize = 0;
            aux = 0;
            proxima_quebra = quebra[i];
            if (!proxima_quebra) proxima_quebra = n;
        }
        if (i != n) resp[aux].push_back(i);
        aux++;
        maiorSize = max(maiorSize, sz[i]);
    }

    cout << r << " " << colum << endl;
    for (int i=0; i<colum; i++){
        cout << szresp[i] << " ";
    }
    cout << endl;

    for (int i=0; i<r; i++){
        for (int j=0; j<resp[i].size(); j++){
            if (resp[i][j] == -1){
                for (int k=0; k<= szresp[j]; k++) cout << ' ';
                continue;
            }
            cout << a[resp[i][j]];

            for (int k=a[resp[i][j]].size(); k<=szresp[j]; k++){
                cout << ' ';
            }
        }
        cout << endl;
    }
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