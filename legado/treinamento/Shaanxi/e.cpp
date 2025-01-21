#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int n,m;
ll ciclos = 0;
bool possible = true;
int t = 1;
int cont2 = 0;

const ll MAX = 2e5+10;
ll conectedTo[MAX];


pair<ll,ll> start;

void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<ll>> &a, vector<vector<bool>> &visited){
    if (i < 0 or i >= n or j < 0 or j >= m) return;
    if (visited[i][j]) return;
    visited[i][j] = true;
    int dx = 0;
    int dy = 0;

    if (mat[i][j] == 'u'){
        dx = -a[i][j];
    }
    if (mat[i][j] == 'd'){
        dx = a[i][j];
    }
    if (mat[i][j] == 'l'){
        dy = -a[i][j];
    }
    if (mat[i][j] == 'r'){
        dy = a[i][j];
    }
    dfs(i+dx, j+dy, mat, a, visited);
    start = {i,j};

}


void solve(){
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    vector<vector<bool>> visited2(n,vector<bool>(m, false));
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            cin >> mat[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited[i][j]) dfs(i,j, mat, a, visited);
        }
    }
    dfs(start.first, start.second, mat, a, visited2);
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited2[i][j]){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}