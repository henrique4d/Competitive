#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int m,n;
        cin >> m >> n;
        bool dp[n][m+10];
        memset(dp, false, sizeof(dp));
        int k;
        cin >> k;
        int val;
        //cout << k << endl;
        for (int i=0; i<k; i++){
            cin >> val;
            if (val <= m)
                dp[0][val] = true;
        }
        for (int i=1; i<n; i++){
            cin >> k;
            //cout << k << endl;
            for (int j=0; j<k; j++){
                cin >> val;
                for (int h=0; h<=m; h++){
                    if (dp[i-1][h] and h+val <=m){
                        dp[i][h+val] = true;
                    }
                }
                
            }
        }
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<=m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // return 0;
        for (int i=m; i>=0; i-- ){
            if (dp[n-1][i]){
                cout << i << endl;
                goto here;
            }
        }
        cout << "no solution\n";
        here:
        int a;
    }
}