#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long ll;
const int MAXN = 1000;
const int MAXDIF = 20000;
#define mod 1000000007

ll dp[MAXN][MAXDIF];
ll offset = 10000;

int main(){
    optimize;
    dp[0][offset] = 1;
    for (int i=0; i<810; i++){
        for (int j=0; j<MAXDIF; j++){
            for (int k=1; k<=9; k++){
                if (i == 0){
                    if (j+k >= 0 and j+k < MAXDIF){
                        dp[i+1][j+k] += dp[i][j]*(9-k);
                        dp[i+1][j+k]%=mod;
                    }
                    if (j-k >= 0 and j-k < MAXDIF){
                        dp[i+1][j-k] += dp[i][j]*(9-k);
                        dp[i+1][j-k] %= mod;
                    }     
                    continue;
                }
                if (j+k >= 0 and j+k < MAXDIF){
                    dp[i+1][j+k] += dp[i][j]*(10-k);
                    dp[i+1][j+k]%=mod;
                }
                if (j-k >= 0 and j-k < MAXDIF){
                    dp[i+1][j-k] += dp[i][j]*(10-k);
                    dp[i+1][j-k] %= mod;
                }
            }
        }
    }

    int q;
    cin >> q;
    int n;
    while (q--){
        cin >> n;
        cout << dp[n][offset] << endl;
    }


}