#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define mod 1000000007
 
const ll MAXN = 2e5+10;
vector<ll> g[MAXN];
bool visited[MAXN];
bool forb[MAXN];
ll dist[MAXN];
 
ll n,m,d,a,b;
 
void init(){
    for (ll i=0; i<n+10; i++){
        visited[i] = false;
    }
}
 
ll eval(){
    ll x = 0;
    init();
 
    vector<pair<ll,ll>> save;
 
    priority_queue<pair<ll,ll>> pq;
    if (!forb[0]){
        pq.push({0,0});
    }
    else save.push_back({0,0});
    
 
    while (true){

        while (!pq.empty()){
            
            auto [w,u] = pq.top();
           
            pq.pop();
            if (visited[u]) continue;
            if (u == n-1){
                dist[x] = -w;
                return x;
            }
            visited[u] = true;

            for (auto v:g[u]) if (!visited[v]){
                if (!forb[v]) pq.push({w-1,v});
                else save.push_back({w-1,v});
            }
        }
        for (auto it:save){
            pq.push(it);
        }
        save.clear();
        x++;
    }
 
    return false;
}
 
 
int main (){
    optimize;
 
    cin >> n >> m >> d;
    for (ll i=0; i<d; i++){
        cin >> a;
        a--;
        forb[a] = true;
    }
    for (ll i=0; i<m; i++){
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    ll resp = eval();
    cout << resp << " " << dist[resp] << endl;
 
 
}