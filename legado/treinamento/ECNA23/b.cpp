#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll MAX = 4e3+10;
ld a[MAX];
ld prefix[MAX];
ld dp[MAX][110];

int n,m,s,k;

ld pre[2010][2010];

ld DP(int i, int k){
    if (dp[i][k] >= 0) return dp[i][k];
    if (i == n+m+1) return 0;
    if (k == 0) return 2e9;
    ld best = 1e9;
    ld soma = 0;
    for (int j=i; j<=n+m; j++){
        best = min(best, pre[i][j] + DP(j+1, k-1));
    }
    return dp[i][k] = best;
}

int main(){
    cin >> n >> m >> k >> s;
    memset(dp,-1, sizeof(dp));
    for (int i=1; i<=n+m; i++){
        cin >> a[i];
    }
    sort(a, a+n+m+1);
    
    for (int i=1; i<=n+m; i++){
        prefix[i] = prefix[i-1] + a[i];
    }

    for (int i=1; i<=n+m; i++){
        for (int j=i; j<=n+m; j++){
            for (int k=i; k<=j; k++){
                pre[i][j] += fabs(a[k] - (prefix[j] - prefix[i-1])/(j-i+1))*fabs(a[k] - (prefix[j] - prefix[i-1])/(j-i+1));    
            }
        }
    }

    ld resp = DP(1,k) + ((ld)s/2.0)*((ld)s/2.0) * (n+m);    
    cout << fixed << setprecision(15) << resp << endl;
}