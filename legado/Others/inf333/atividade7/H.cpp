#include <bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>> &M, vector<vector<int>>&dp, int i, int j, int cont){
    //cout << i << " " << j << " " << dp[i][j] << endl;
    if (dp[i][j] != -1) return dp[i][j];
    if (M[i][j] == INTMAX_MAX) return -1;

    dp[i][j] = 1;
   
    if (M[i-1][j] < M[i][j]){
        dp[i][j] =  max(dfs(M, dp, i-1, j, cont+1)+1, dp[i][j]);
    }
    if (M[i+1][j] < M[i][j]){
        dp[i][j] =  max(dfs(M, dp, i+1, j, cont+1)+1, dp[i][j]);
    }
    if (M[i][j-1] < M[i][j]){
        dp[i][j] =  max(dfs(M, dp, i, j-1, cont+1)+1, dp[i][j]);
    }
    if (M[i][j+1] < M[i][j]){
        dp[i][j] =  max(dfs(M, dp, i, j+1, cont+1)+1, dp[i][j]);
    }
    return dp[i][j];
}




int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        string nome;
        cin >> nome;
        cout << nome << ": ";
        int best = 0;
        int n,m;
        cin >> n >> m;
        vector<vector<int>> M(n+2,vector<int>(m+2, INT_MAX));
        vector<vector<int>> dp(n+2,vector<int>(m+2, -1));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> M[i+1][j+1];
            }
        }
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (dp[i][j] == -1){
                    best = max(best,dfs(M, dp,i,j, 0));
                    //cout <<  << endl;
                }
            }
        }
        cout << best << endl;
        //cout << "//////////////////" << endl;
     
    }
}