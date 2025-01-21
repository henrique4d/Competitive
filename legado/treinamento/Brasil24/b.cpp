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
#define MOD 1000000007LL
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
const ll MAXM = 1e6+10;
vector<ll> movies[MAXM];
vector<ll> atores[MAXM];
bool visited[110];
pair<int,int> from[110];
int path[110][110];

ll n,m;

void init(){

    for (int i=0; i<= n; i++){
        visited[i] = false;
        from[i] = {-1,-1};
    }
}

void dfs(int u, int movieFrom, int atorFrom){
    if (visited[u]) return;
    visited[u] = true;
    from[u] = {movieFrom,atorFrom};

    for (int i=1; i<=n; i++){
        if (path[u][i] ){
            dfs(i,u,path[u][i]);
        }
    }
}



void solve(){
    cin >> n >> m;
    int ator;
    int k;
    for (int i=1; i<=n; i++){
        cin >> k;
        for (int j=0; j<k; j++){
            cin >> ator;
            movies[ator].push_back(i);
            atores[i].push_back(ator);
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=0; j<movies[i].size(); j++){
            for (int k=j+1; k<movies[i].size(); k++){
                path[movies[i][j]][movies[i][k]] = i;
                path[movies[i][k]][movies[i][j]] = i;
            }
        }
    }
    ll q;
    cin >> q;

    while (q--){
        init();
        int origin, dest;
        cin >> origin >> dest;

        for (auto x:movies[origin]) dfs(x,-1,-1);
        
        vector<ll> resp;
        for (auto x:movies[dest]){
            if (visited[x] and !resp.size()){
                int atual = x;
                resp.push_back(dest);
                resp.push_back(x);

                while (from[atual].first != -1){
                    resp.push_back(from[atual].second);
                    resp.push_back(from[atual].first);     
                    atual = from[atual].first;
                }
                resp.push_back(origin);
            }
        }
        if (!resp.size()){
            cout << -1 << endl;
            continue;
        }
        cout << resp.size()/2 + 1 << endl;
        reverse(all(resp));
        for (auto x:resp){
            cout << x << " ";
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