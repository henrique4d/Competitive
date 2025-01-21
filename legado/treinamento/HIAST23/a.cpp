#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

const ll MAXN = 100+10;
const ll MAXM = 6e4+10;
ll dp[MAXN][MAXM];
ll a[MAXN];
int cont[12];
int cont2[12];
int cont3[12];
int n;

void init(){
    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXM; j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
}




void solve(){
    cin >> n;
    init();
    ll best = 0;

    for (int i=0; i<n; i++){
        cin >> a[i];
        for (ll estado = 0; estado < MAXM; estado++){
            if (dp[i][estado] == -1) continue;
            for (int j=0; j<=10; j++){
                cont[j] = 0;
                cont2[j] = 0;
            }

            ll aux = a[i];
            
            while (aux){
                cont[aux%10]++;
                aux/=10;
            }

            ll jaux = estado;
            for (int k =0; k<10; k++){
                cont2[k] = jaux%3;
                jaux/=3;
            }
        

            bool possopegar = true;
            for (int j=0; j<10; j++){
                cont3[j] = cont[j]+cont2[j];
                if (cont3[j] > 2) possopegar = false;
            }

            if (possopegar){
                ll proximoestado = 0;
                ll aux = 1;
                for (int j=-0; j<10; j++){
                    proximoestado += cont3[j]*aux;
                    aux*=3;
                }
                dp[i+1][proximoestado] = max(dp[i+1][proximoestado], dp[i][estado] + a[i]);
                best = max(best, dp[i+1][proximoestado]);
            }
            dp[i+1][estado] = max(dp[i+1][estado], dp[i][estado]);
            best = max(best, dp[i+1][estado]);
        }
    }

    cout << best << endl;
}

int main(){
    optimize
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}