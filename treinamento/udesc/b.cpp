#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

ll modPow(ll a, ll b){
    ll resp = 1;
    a%=3;
    while(b>0){
        if (b&1) resp*=a;
        a*=a;
        a%=3;
        b>>=1;
    }
    return resp;
}

const ll MAXN = 4e5+10;

bool dp[MAXN][4][3];
bool calc[MAXN][4][3];


ll n,k;


bool DP(ll tam, ll rest, ll player){
    
    if (tam == n+k){
        return rest == 0;
    }

    if (calc[tam][rest][player]){
        return dp[tam][rest][player];
    }

    if (player){
        if (DP(tam+1, rest, !player) or DP(tam+1, (rest + modPow(2,tam))%3, !player) or DP(tam+1, (rest*2)%3, !player) or DP(tam+1, (rest*2+1)%3, !player) ){
            calc[tam][rest][player] = true;
            return dp[tam][rest][player] = true;
        }
        else{
            calc[tam][rest][player] = true;
            return dp[tam][rest][player] = false;
        }
    }
    if (!player){
        if (!DP(tam+1, rest, !player) or !DP(tam+1, (rest + modPow(2,tam))%3, !player) or !DP(tam+1, (rest*2)%3, !player) or !DP(tam+1, (rest*2+1)%3, !player) ){
            calc[tam][rest][player] = true;
            return dp[tam][rest][player] = false;
        }
        else{
            calc[tam][rest][player] = true;
            return dp[tam][rest][player] = true;
        }
    }

    return true;
}


int main (){
    optimize;

    cin >> n >> k;
    k*=2;
    string s;
    cin >> s;
    int atual = 0;
    
    for (int i=0; i<n; i++){
        if (s[i] == '1'){
            atual += modPow(2,n-i-1);
            atual%=3;
        }
    }

    cout << (DP(n,atual,0)?"JULIA\n":"GIOVANA\n");
}