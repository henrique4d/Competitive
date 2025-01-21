#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int MAX = 2048576;
int balance[25];
bool zero[MAX];
int dp[MAX];
int n,m;
    
void setzero(int s){
    int val = 0;
    for (int i=0; i<n; i++){
        if (s&(1<<i)) val += balance[i];
    }
    zero[s] = val==0;

}

int DP(int s){
    if (dp[s] != -1) return dp[s];

    int maior = -1;
    
    for (int i=0; i<n; i++){
        if (s&(1<<i)) maior = max(maior, DP(s^(1<<i)));
    }

    return dp[s] = maior + zero[s];
}

int main(){
    cin >> n >> m;
    int a,b, c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        balance[a] += c;
        balance[b] -= c;
    }
    dp[0] = 0;

    for (int i=0; i<(1<<n); i++){
        setzero(i);
        dp[i] = -1;
    }
    
    // cout << dp[(1<<n)-1] << endl;

    cout << n - DP((1<<n)-1) << endl;

}