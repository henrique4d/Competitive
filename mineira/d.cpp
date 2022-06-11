#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    long long int cidades[n][m];
    long long int acumuladolinha[n][m-k+1];
    long long int acumuladocoluna[n-k+1][m-k+1];

    memset(cidades, 0, sizeof(cidades));
    for (int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cin >> cidades[a][b];
    }

    for (int i=0; i<n; i++){
        multiset<long long int> acumulado;
        for (int j=0; j<k; j++){
            acumulado.insert(cidades[i][j]);
        }
        if (*acumulado.begin() == 0){
            acumuladolinha[i][0] = 0;
        }
        else{ 
            auto maior = acumulado.end();
            maior--;
            acumuladolinha[i][0] = *maior;
        }

        for (int j=1; j<m-k+1; j++){ 
            acumulado.erase(acumulado.lower_bound(cidades[i][j-1]));
            acumulado.insert(cidades[i][j+k-1]);

            if (*acumulado.begin() == 0){
                acumuladolinha[i][j] = 0;
            }
            else{
                auto maior = acumulado.end();
                maior--;
                acumuladolinha[i][j] = *maior;
            }
        }
    }

    for (int j=0; j<m-k+1; j++){
        multiset<long long int> acumulado;
        for (int i=0; i<k; i++){
            acumulado.insert(acumuladolinha[i][j]);
        }
        if (*acumulado.begin() == 0){
            acumuladocoluna[0][j] = 0;           
        }
        else{
            auto maior = acumulado.end();
            maior--;
            acumuladocoluna[0][j] = *maior;
        }

        for (int i=1; i<n-k+1; i++){
            acumulado.erase(acumulado.lower_bound(acumuladolinha[i-1][j]));
            acumulado.insert(acumuladolinha[i+k-1][j]);
            if (*acumulado.begin() == 0){
                acumuladocoluna[i][j] = 0;           
            }
            else{
                auto maior = acumulado.end();
                maior--;
                acumuladocoluna[i][j] = *maior;
            }
        }       
    }
    long long int menor = -1;
    for (int i=0; i<n-k+1; i++){
        for (int j=0; j<m-k+1; j++){
            if (acumuladocoluna[i][j] != 0){
                if (menor == -1){
                    menor = acumuladocoluna[i][j];
                }
                else{
                    menor = min(menor, acumuladocoluna[i][j]);
                }
            }
        }
    }
    cout << menor << endl;
}