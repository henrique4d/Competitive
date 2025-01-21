#include <bits/stdc++.h>
 
using namespace std;
#define f(i,s,e) for(long long int i=s;i<e;i++)
 
#define pb push_back
#define fi first
#define se second
 
typedef long long ll;
typedef long double ld;
typedef pair<long long int,long long int> pii;
typedef pair<ll, ll> pll;
 
#define all(x) (x).begin(),x.end()
#define endl '\n'
/* PRlong long long long intS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}\n"; }
/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,long long int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
// ll max(ll a,long long int b) { if (a>b) return a; return b; }
// ll max(long long int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (long long int i=0;i<(long long int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (long long int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }



vector<vector<long long int>> up;
vector<vector<long long int>> d1; //valor para "descer"
vector<vector<long long int>> d2; //valor para "subir"
long long int n;
long long int LOG;

vector<long long int> depth;
vector<bool> visited;


void dfs(list<pair<long long int,pair<long long int,long long int>>> sons[], long long int pos){
    visited[pos] = true;
    for (pair<long long int,pair<long long int,long long int>> son : sons[pos]){
    
        if (visited[son.first]) continue;
        up[son.first][0] = pos;
        d1[son.first][0] = son.second.first;
        d2[son.first][0] = son.second.second;
        depth[son.first] = depth[pos] + 1;
        dfs(sons, son.first);
    }
}

void binary_lifting(list<pair<long long int,pair<long long int,long long int>>> sons[]){
    for (long long int i=1; i<=LOG; i++){
        for (long long int j=0; j<n; j++){
            up[j][i] = up[up[j][i-1]][i-1];
            d1[j][i] = d1[j][i-1] + d1[up[j][i-1]][i-1];
            d2[j][i] = d2[j][i-1] + d2[up[j][i-1]][i-1];

        }
    }
}


long long int getPathVal(long long int a, long long int b){
    long long int val = 0;
    //cout << "incialmente " << a << " " << b << " " << val << endl;
    //cout << a << " " << b << " " << depth[a] << " " << depth[b] << endl;
    if (depth[a] > depth[b]){
        long long int dist = depth[a] - depth[b];
        for (long long int i=LOG; i>=0; i--){
            if ( dist >= pow(2,i)){
                val += d1[a][i];
                a = up[a][i];
                dist -= pow(2,i);
            }
        }
    }

    //cout << a << " " << b << endl;
    if (depth[b] > depth[a]){
        long long int dist = depth[b] - depth[a];
        for (long long int i=LOG; i>=0; i--){
            if ( dist >= pow(2,i)){
                val += d2[b][i];
                //cout << "andando de " << b << " para " << up[b][i] << " com custo " << d2[b][i] << " " << i << endl;
                b = up[b][i];
                dist -= pow(2,i);
            }
        }
    }


    //cout << "depois de igualar as alturas " << a << " " << b << " " << val << endl;
    //cout << a << " " << b << endl;

    if (a == b) return val;
    
    for (long long int i=LOG; i>=0; i--){
        if ( up[a][i] != up[b][i]){
            val += d1[a][i];
            val += d2[b][i];
            a = up[a][i];
            b = up[b][i];
        }
    }
    //cout << "depois de andar para o lca - 1 " << a << " " << b << " " << val << endl;
    

    //cout << a << " " << b << endl;

    val += d1[a][0];
    val += d2[b][0];
    //cout << "aqui : " << d1[a][0] << " " << d2[b][0] << endl;
    a = up[a][0];
    b = up[b][0];

    //cout << "final " << a << " " << b << " " << val << endl;
    
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int z;
    cin >> z;
    up = vector<vector<long long int>> (100010, vector<long long int>(25));
    d1 = vector<vector<long long int>> (100010, vector<long long int>(25));
    d2 = vector<vector<long long int>> (100010, vector<long long int>(25));
    
    list<pair<long long int,pair<long long int,long long int>>> sons[100010];
    depth = vector<long long int>(100010);       
    visited = vector<bool>(100010,false);

    while(z--){
        cin >> n;
        LOG = log2(n)+1;
      
        for (int i=0; i<n; i++){
            sons[i].clear();
            visited[i] = false;
            }
        long long int soma = 0;
        long long int u,v,c1,c2;
        f(i,0,n-1){
            cin >> u >> v >> c1 >> c2;
            u--;
            v--;
            sons[u].pb({v, {c1,c2}});
            sons[v].pb({u, {c2,c1}});
            soma += c1;
            soma += c2;
        }

        up[0][0] = 0;
        d1[0][0] = 0;
        d2[0][0] = 0;
        depth[0] = 0;
        dfs(sons,0);
        binary_lifting(sons);

        long long int q;
        cin >> q;
        long long int l,r;
        while(q--){
            cin >> l >> r;
            l--;
            r--;
            long long int teste = getPathVal(l,r);
            cout << soma - teste << endl;           
        }
    }
}