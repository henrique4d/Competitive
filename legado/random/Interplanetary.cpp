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
const int MAX = 500;
int g[MAX][MAX];
vector<int> temp;
pair<int,int> temperatura[MAX];
int dist[MAX][MAX];
int n,m,q,a,b,c;

struct Query{
    int start,end,k,t, index;
};
bool compare(Query a, Query b){
    return a.k < b.k;
}

void init(){
    for (int i=0; i<n+10; i++){
        for (int j=0; j<n+10; j++){
            dist[i][j] = INF;
            if (i == j) dist[i][j] = 0;
            if (g[i][j]){
                dist[i][j] = g[i][j];
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    temp.resize(n);
    for (int i=0; i<n; i++){
        cin >> temp[i];
        temperatura[i].first = temp[i];
        temperatura[i].second = i;
    }
    sort(temperatura, temperatura+n);
    sort(all(temp));
    
    temp.resize(unique(all(temp)) - temp.begin());
    // cout << temp << endl;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        a--,b--;
        g[a][b] = c;
        g[b][a] = c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    cin >> q;
    
    vector<Query> quer(q);
    vector<int> resp(q);
    for (int i=0; i<q; i++){
        cin >> quer[i].start >> quer[i].end >> quer[i].k >> quer[i].t;
        quer[i].start--;
        quer[i].end--;
        quer[i].index = i;
    }
    sort(all(quer), compare);

    int k = 0;
    init();
    for (auto query:quer){
        if (!query.t){
                while (k < n and temperatura[k].first <= temp[query.k-1]){
                int aux = temperatura[k].second;
                for (int i=0; i<n; i++){
                    for (int j=0; j<n; j++){
                        if (dist[i][aux] + dist[aux][j] < dist[i][j]) dist[i][j] = dist[i][aux] + dist[aux][j];
                    }
                }
                k++;
            }
            resp[query.index] = dist[query.start][query.end];
        }
    }

    init();

    reverse(temperatura, temperatura + n);
    reverse(all(temp));
    k = 0;
    for (auto query:quer){
        if (query.t){
                while (k < n and temperatura[k].first >= temp[query.k-1]){
                int aux = temperatura[k].second;
                for (int i=0; i<n; i++){
                    for (int j=0; j<n; j++){
                        if (dist[i][aux] + dist[aux][j] < dist[i][j]) dist[i][j] = dist[i][aux] + dist[aux][j];
                    }
                }
                k++;
            }
            resp[query.index] = dist[query.start][query.end];  
        }
    }

    for (int i=0; i<q; i++){
        if (resp[i] == INF) cout << -1 << endl;
        else cout << resp[i] << endl;
    }
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