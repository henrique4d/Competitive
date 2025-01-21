#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 150;
vector <pair<ll,ll>> a;
ll n;

vector<ll> adj[MAX*MAX];
bool visited[MAX*MAX];
ll pre[MAX*MAX];
ll lastVisited;

void dfs(ll u){
    visited[u] = true;
    lastVisited = u;
    for (auto v:adj[u]) if (!visited[v]){
        dfs(v);
    }
}

ll t = 1;
void dfsPrint(ll u){
    pre[u] = t++;
    for (auto v:adj[u]){
        if (!pre[v]){
            dfsPrint(v);
            cout << a[v].first+1 << " " << a[v].second+1 << " " << a[u].first+1 << " " << a[u].second+1 << endl;
        }
    }
}

int main(){
    cin >> n;
    char tipo;
    char tipoGeral = '-';

    cin >> tipoGeral;
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cin >> tipo;
            if (tipo == '.') continue;
            if (tipo != tipoGeral){
                cout << "NO\n";
                return 0;
            }
            a.push_back({i,j});
        }
    }

    if (tipoGeral == '-'){
        cout << "NO\n";
        return 0;
    }
    for (ll i=0; i<a.size(); i++){
        for (ll j=i+1; j<a.size(); j++){
            if (tipoGeral == 'R' and (a[i].first-a[j].first == 0 or a[i].second - a[j].second == 0)){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            if (tipoGeral == 'Q' and (a[i].first-a[j].first == 0 or a[i].second - a[j].second == 0
                or a[i].first - a[i].second == a[j].first - a[j].second
                or a[i].first + a[i].second == a[j].first + a[j].second)){
                adj[i].push_back(j);
                adj[j].push_back(i);    
            }
            if (tipoGeral == 'B' and ( a[i].first - a[i].second == a[j].first - a[j].second
                or a[i].first + a[i].second == a[j].first + a[j].second)){
                adj[i].push_back(j);
                adj[j].push_back(i);    
            }
            if (tipoGeral == 'N' and ( (abs(a[i].first-a[j].first) == 1 and abs(a[i].second - a[j].second) == 2) or (abs(a[i].first-a[j].first) == 2 and abs(a[i].second - a[j].second) == 1)) ){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
            if (tipoGeral == 'K' and ( (abs(a[i].first-a[j].first) <= 1) and (abs(a[i].second-a[j].second) <= 1 )) ){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }       
        }
    }
    dfs(0);
    for (ll i=1; i<a.size(); i++){
        if (!visited[i]){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    dfsPrint(lastVisited);

}