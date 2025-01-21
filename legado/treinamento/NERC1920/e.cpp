#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
using namespace std;
typedef long long ll;

const ll MAXN = 2e5+10;
vector<int> g[MAXN];
ll n,m;
bool visited[MAXN];
ll cont[MAXN];

void solve() {
    cin >> n >> m;
    int u,v;
    for (int i=0; i<n-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x;
    set<int> proximos;
    
    queue<int> q;
    
    for (int i=0; i<m; i++){
        cin >> x;
        cont[x]++;
        if (cont[x] == m){
            cout << "YES\n";
            cout << x << endl;
            return;
        }
        visited[x] = true;
        q.push(x);
    }

    while (!q.empty()){
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for (auto v:g[u]){
                if (!visited[v]){
                    cont[v] += cont[u];
                    proximos.insert(v);
                }
            }
        }
        for (auto x:proximos){
            if (cont[x] == m){
                cout << "YES\n";
                cout << x << endl;
                return;
            }
            visited[x] = true;
            q.push(x);
        }
        proximos.clear();
    }

    cout << "NO\n";
}
 
int main() {
    optimize;
    int numCases = 1;
    // cin >> numCases;
 
    for(int i = 0; i < numCases; i++) solve();
 
    return 0;
}