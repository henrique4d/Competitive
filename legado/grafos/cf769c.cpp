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


void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    if (k&1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vector<char>> tab(n+10,vector<char>(m+10,'*'));
    vector<vector<ll>> dist(n+10,vector<ll>(m+10,INF));
    vector<vector<bool>> visited(n+10,vector<bool>(m+10,false));


    pair<ll,ll> atual = {-1,-1};
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> tab[i][j];
            if (tab[i][j] == 'X'){
                atual = {i,j};
                tab[i][j] = '.';
            }
        }
    }

    dist[atual.first][atual.second] = 0;

    queue<pair<pair<int,int>,int>> q;
    q.push({atual,0});
    visited[atual.first][atual.second] = true;

    while (!q.empty()){
        auto [i,j] = q.front().first;
        auto w = q.front().second;
        dist[i][j] = w;
        q.pop();

        int di = 0;
        int dj = -1;
        int aux = 4;
        while(aux--){
            if (!visited[i+di][j+dj] and tab[i+di][j+dj] == '.'){
                visited[i+di][j+dj] = true;
                q.push({{i+di, j+dj},w+1});
            }
            swap(di,dj);
            dj*=-1;
        }
    }


    if (atual == make_pair((ll)-1,(ll)-1)){
        cout << "IMPOSSIBLE\n";
        return;
    }

    string resp;
    for (int i=0; i<k; i++){
        if (tab[atual.first+1][atual.second] == '.' and dist[atual.first+1][atual.second]+i < k){
            atual.first++;
            resp.push_back('D');
        }
        else if (tab[atual.first][atual.second-1] == '.' and dist[atual.first][atual.second-1]+i < k){
            atual.second--;
            resp.push_back('L');
        }
        else if (tab[atual.first][atual.second+1] == '.' and dist[atual.first][atual.second+1]+i < k){
            atual.second++;
            resp.push_back('R');
        }
        else if (tab[atual.first-1][atual.second] == '.' and dist[atual.first-1][atual.second]+i < k){
            atual.first--;
            resp.push_back('U');
        }
        else{
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

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