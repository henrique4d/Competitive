#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    while (z--){
        int n;
        cin >> n;
        int gaiolas = 0;
        int maximo = 0;
        int quant_atual = 0;
        int ocupadas = 0;

        int aux;
        for (int i=0; i<n; i++){
            cin >> aux;
            if (aux == 1){
                ocupadas++;
                if (ocupadas > gaiolas) gaiolas = ocupadas;
                quant_atual++;
            }
            else{
                int wtf = (quant_atual+1)/2;
                ocupadas = quant_atual/2;

                if (wtf%2 == 1){
                    if (ocupadas%2 == 0) ocupadas+=2;
                    else ocupadas++;
                }
                //if (quant_atual == 1) ocupadas = 1;
                //if (quant_atual == 2) ocupadas = 2;
                //ocupadas = (quant_atual+2)/2;
                //quant_atual = min(quant_atual, (quant_atual+1)/2);
            }
            if (ocupadas > gaiolas) gaiolas = ocupadas;
            //cout << quant_atual << endl;
            maximo = max(maximo, gaiolas);
            cout << ocupadas << " " << quant_atual << endl;
        }
        cout << maximo << endl;
        cout << "////////\n";
    }
}