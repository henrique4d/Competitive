#include <bits/stdc++.h>

using namespace std;

typedef int ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(x) x.begin(),x.end()

const ll MAXN = 1e3 + 10;
const ll MAXDIST = 1e4+10;

int main(){
    optimize;

    ll n,m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<ll,ll>>> prevv(n+1, vector<pair<ll,ll>>(k+1, {0,0}));
    vector<vector<bool>> vis(n+1, vector<bool>(k+1, false));
    vector<vector<pair<ll,ll>>> adj(n+1);

    ll start, end;
    cin >> end >> start;
    ll a,b, c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        if (c > k) continue;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    stack<pair<ll,ll>> q;

    q.push({start, 0});
    vis[start][0] = true;

    vector<ll> resp;

    while (!q.empty()){
        auto atual = q.top();
    
        q.pop();

        for (auto v:adj[atual.first]){
            if (atual.second + v.second > k) continue;
            
            if (atual.second + v.second == k and v.first == end){
                resp.push_back(end);
                while (atual.first != 0){
                    resp.push_back(atual.first);
                    atual = prevv[atual.first][atual.second];
                }
                goto here;
                //achou resposta
            }

            if ( !vis[v.first][atual.second + v.second] ){
                prevv[v.first][atual.second + v.second] = atual;                
                vis[v.first][atual.second + v.second] = true;
                q.push({v.first, atual.second + v.second});
            }
        }
    }
    cout << "Impossible\n";
    return 0;
    here:
    for (auto it = resp.begin(); it!=  resp.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}