#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        int budget, hotels, dias;
        cin >> budget >> hotels >> dias;

        int menor = -1;
        for (int i=0; i<hotels; i++){
            int preco;
            cin >> preco;
            for (int k=0; k<dias; k++){
                int vagas;
                cin >> vagas;
                if (vagas >= n and preco*n <= budget ){
                    menor = min(menor, preco*n);
                    if (menor == -1) menor = preco*n;
                }
            }
        }

        if(menor == -1){
            cout << "stay home\n";
        }
        else cout << menor << endl;
    }
}