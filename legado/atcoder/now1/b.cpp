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
 
#define mod 1000000007LL
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//#define _DEBUG
// #ifdef _DEBUG
// #endif
 
/* -------------------------------- Solution starts below -------------------------------- */
 
int T;
const int MAXN = 100+10;

vector<ll> neighbor[MAXN];
bool visited[MAXN];
ll cont = 0;
ll origem;

void dfs(int u){
    if (visited[u]) return;
    visited[u] = true;
    cont++;
    for (auto v:neighbor[u]){
        if (v == origem){
            cont = INT_MIN;
            return;
        }
        dfs(v);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    int a,b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        neighbor[a].push_back(b);
    }
    int resp = -1;
    for (int i=0; i<n; i++){
        cont = 0;
        origem = i;
        memset(visited, false, sizeof(visited));
        dfs(i);
        if (cont < 0){
            cout << -1 << endl;
            return;
        }
        if (cont == n){
            if (resp == -1) resp = i+1;
            else{
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << resp << endl;

}
 
int main() {
 
	// optimize;
	
	T = 1;
	
	//cin >> T;
 
    while(T--) {
		solve();
    }
 
	return 0;
}