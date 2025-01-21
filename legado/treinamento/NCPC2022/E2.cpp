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
const int MAXN = 3e3 + 10;
vector<int> neighbors[MAXN];
int visited[MAXN];

int n,m;
    

int get_ciclo(int pos){
    for (int i=0; i<n; i++){
        visited[i] = -1;
    }

    int dist = 0;
    queue<int> toprocess;
    toprocess.push(pos);
    visited[pos] = dist;
    visited[pos] = 0;

    while(!toprocess.empty()){
        int tam = toprocess.size();
        dist++;
        while (tam--){
            int atual = toprocess.front();
            cout << "processando o vertice " << atual << endl;
            toprocess.pop();
            if (atual == pos and dist > 1) return dist;
            for (auto neigh:neighbors[atual]){
                if (visited[neigh] != -1) continue;
                visited[neigh] = dist;
                toprocess.push(neigh);
            }

        }
    }

    return -1;

}

void solve(){
    cin >> n >> m;
    int a,b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    int menor = 0;
    for (int i=0; i<n; i++){
        menor = min(menor, get_ciclo(i));
        cout << "///////////\n";
    }
    cout << menor << endl;

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