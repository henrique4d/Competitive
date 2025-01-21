#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

const ll MAXN = 1e3+10;
char a[MAXN][MAXN];

ll n,m;

void dfs(int i, int j){
    a[i][j] = '#';

    int di = -1;
    int dj = 0;
    int aux = 4;
    while (aux--){
        if (a[i+di][j+dj] == '.') dfs(i+di, j+dj);
        swap(di,dj);
        dj *= -1;
    }
}
int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (a[i][j] == '.'){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
}