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
const ll MAX = 120;
ll tab[MAX][MAX];
bool borda[MAX][MAX];
bool visited[MAX][MAX];
bool visited2[MAX][MAX];

void init(){
    for (ll i=0; i<MAX; i++){
        for (ll j=0; j<MAX; j++){
            tab[i][j] = 0;
            borda[i][j] = false;
            visited[i][j] = false;
            visited2[i][j] = false;
        }
    }
}

void solve(){
    ll n,m;
    init();
    cin >> n >> m;
    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=m; j++){
            cin >> tab[i][j];
        }
    }

    queue<pair<ll,ll>> q;

    for (ll i=1; i<=n; i++){
        for (ll j=1; j<=m; j++){
            if ((i == 1 or j == 1 or i == n or j == m) and !visited[i][j]){
                visited[i][j] = true;
                borda[i][j] = true;
                q.push({i,j});
                while (!q.empty()){
                    ll aux = 4;
                    ll dx = -1;
                    ll dy = 0; 
                    auto [x,y] = q.front();
                    q.pop();
                        
                    while (aux--){
                        if (tab[x+dx][y+dy] != 0 and !visited[x+dx][y+dy] and tab[x+dx][y+dy] > tab[x][y]){
                            borda[x+dx][y+dy] = true;
                            visited[x+dx][y+dy] = true;
                            q.push({x+dx, y+dy});
                        }
                        swap(dx,dy);
                        dy*=-1;
                    }
                }
                
            }
        }
    }

    ll resp = 0;
    for (ll i=1; i<=n; i++){
        for (ll j =1; j<=m; j++){
            if (!visited[i][j]){
                ll val_borda = INFLL;
                q.push({i,j});
                visited[i][j] = true;
                while (!q.empty()){
                    auto[x,y] = q.front();
                    q.pop();
                    ll aux = 4;
                    ll dx = 1;
                    ll dy = 0;
                    while (aux--){
                        if (!borda[x+dx][y+dy] and !visited[x+dx][y+dy]){
                            visited[x+dx][y+dy] = true;
                            q.push({x+dx, y+dy});
                        }
                        else if (borda[x+dx][y+dy]){
                            val_borda = min(val_borda, tab[x+dx][y+dy]);
                        }
                        swap(dx,dy);
                        dy*=-1;
                    }
                }
                
                q.push({i,j});
                visited2[i][j] = true;
                while (!q.empty()){
                    auto[x,y] = q.front();
                    q.pop();
                    ll aux = 4;
                    ll dx = 1;
                    ll dy = 0;
                    resp += max(val_borda-tab[x][y], (ll)0);
                
                    while (aux--){
                        if (!borda[x+dx][y+dy] and !visited2[x+dx][y+dy]){
                            visited2[x+dx][y+dy] = true;
                            q.push({x+dx, y+dy});
                        }
                        swap(dx,dy);
                        dy*=-1;
                    }
                }

            }
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