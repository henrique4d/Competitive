#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

typedef long long ll;
const int MAXN = 1e6+10;
ll p[MAXN];
bool vis[MAXN];
int n;
ll resp = 0;

int dfs(int u){
    if (vis[u]) return 0;
    vis[u] = true;
    return dfs(p[u])+1;
}

int main(){
    optimize;
    cin >> n;
    int x;
    for (int i =1; i<=n; i++){
        cin >> p[i];
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            resp += dfs(i)-1;
        }
    }

    for (int i =1; i<=n; i++){
        cin >> p[i];
        vis[i] = false;
    }
    for (int i=1; i<=n; i++){
        if (!vis[i]){
            resp += dfs(i)-1;
        }
    }

    cout << resp << endl;


}