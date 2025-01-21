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
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
//bool prime(ll a) { if (a==1) return 0; for (long long ll i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//#define _DEBUG
// #ifdef _DEBUG
// #endif

/* -------------------------------- Solution starts below -------------------------------- */ 

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> tab(n+10, vector<char>(m+10, 'w'));
    vector<vector<bool>> visited(n+10, vector<bool>(m+10, false));
    vector<vector<ll>> dist1(n+10, vector<ll>(m+10, 0));
    vector<vector<ll>> dist2(n+10, vector<ll>(m+10, 0));
    vector<vector<ll>> dist3(n+10, vector<ll>(m+10, 0));
    vector<pair<int,int>> start;


    deque<pair<pair<int,int>,int>> q;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> tab[i][j];
            if (tab[i][j] == 'T') q.push_back({{i,j},0}), visited[i][j] = true;
            if (tab[i][j] == '*') start.push_back({i,j});
        }
    }

    while (!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        ll d = q.front().second;
        q.pop_front();
        dist1[i][j] = d;
  
        if (tab[i][j] == 'w') continue; 
        int di = -1;
        int dj = 0;
        int aux = 4;
        while(aux--){            
            if (visited[i+di][j+dj]);
            else if (tab[i+di][j+dj] == '.'){
                q.push_back({{i+di, j+dj},d+1});
                visited[i+di][j+dj] = true;
            }
            else if (tab[i+di][j+dj] == '#' or tab[i+di][j+dj] == '*' or tab[i+di][j+dj] == 'T'){
                q.push_front({{i+di, j+dj},d});
                visited[i+di][j+dj] = true;
            }
            swap(di,dj);
            dj*=-1;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            visited[i][j] = false;
        }
    }
    q.push_back({start[0],0});
    visited[start[0].first][start[0].second] = true;
    while (!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        ll d = q.front().second;
        q.pop_front();
        dist2[i][j] = d;
     
        if (tab[i][j] == 'w') continue; 
        int di = -1;
        int dj = 0;
        int aux = 4;
        while(aux--){            
            if (visited[i+di][j+dj]);
            else if (tab[i+di][j+dj] == '.'){
                q.push_back({{i+di, j+dj},d+1});
                visited[i+di][j+dj] = true;
            }
            else if (tab[i+di][j+dj] == '#' or tab[i+di][j+dj] == '*' or tab[i+di][j+dj] == 'T'){
                q.push_front({{i+di, j+dj},d});
                visited[i+di][j+dj] = true;
            }
            swap(di,dj);
            dj*=-1;
        }
    }

    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            visited[i][j] = false;
        }
    }
    q.push_back({start[1],0});
    visited[start[1].first][start[1].second] = true;
    while (!q.empty()){
        int i = q.front().first.first;
        int j = q.front().first.second;
        ll d = q.front().second;
        q.pop_front();
        dist3[i][j] = d;

        if (tab[i][j] == 'w') continue; 
        int di = -1;
        int dj = 0;
        int aux = 4;
        while(aux--){            
            if (visited[i+di][j+dj]);
            else if (tab[i+di][j+dj] == '.'){
                q.push_back({{i+di, j+dj},d+1});
                visited[i+di][j+dj] = true;
            }
            else if (tab[i+di][j+dj] == '#' or tab[i+di][j+dj] == '*' or tab[i+di][j+dj] == 'T'){
                q.push_front({{i+di, j+dj},d});
                visited[i+di][j+dj] = true;
            }
            swap(di,dj);
            dj*=-1;
        }
    }


    ll ans = dist1[start[0].first][start[0].second] + dist1[start[1].first][start[1].second];

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m;j++){
            ans = min(ans, dist1[i][j] + dist2[i][j] + dist3[i][j] - 2*(tab[i][j] == '.'));
        }
    }
    cout << ans << endl;
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