#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long ll;
const int MAXN = 1e3+10;
set<int> g[MAXN];
int n,k;

int main(){
    optimize;
    cin >> n >> k;
    int u,v;
    for (int i=0; i<k; i++){
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    if (n == 1){
        cout << "NO\n";
        return 0;
    }
    vector<pair<int,int>> resp;

    for (int i=1; i<=n/2; i++){
        for (int j=1; j<=n/2; j++){
            if (i == j) continue;
            if (g[i].find(j) == g[i].end()){
                g[i].insert(j);
                g[j].insert(i);
                resp.push_back({i,j});
            }
        }
    }
    

    for (int i=n/2+1; i<=n; i++){
        for (int j=n/2+1; j<=n; j++){
            if (i == j) continue;
            if (g[i].find(j) == g[i].end()){
                g[i].insert(j);
                g[j].insert(i);
                resp.push_back({i,j});
            }
        }
    }
    cout << "YES\n";
    cout << resp.size() << endl;
    for (auto [u,v]:resp){
        cout << u << " " << v << endl;
    }

}