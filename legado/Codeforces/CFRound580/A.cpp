#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 1e6+5;
    pair<pair<int,int>, pair<int,int>> dp[n];
    bool aux = true;
    bool aux2 = true;
    int trocar = 2;

    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int cont4 = 0;
    bool cor = true;
    int pos = 0;

    for (int i=0; i<n;){
        for (int j=0; j <=pos and j<=n and i<=n; j++){
            if (aux){
                if (cor) cont1++;
                else cont2++;
            }
            else {
                if (cor) cont3++;
                else cont4++;
            }
            dp[i] = { {cont1,cont2}, {cont3, cont4}};
            //cout << i << " " << cont1 << " " << cont2 << endl;
            i++;
            cor = !cor;
        }
        pos++;
        if (aux2){
            aux = !aux;
            aux2 = false;
        }
        else aux2 = true;
    }

    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int pos;
        cin >> pos;
        pos--;
        cout << dp[pos].first.first << " " << dp[pos].first.second << " " << dp[pos].second.first << " " << dp[pos].second.second << endl;
    }
}