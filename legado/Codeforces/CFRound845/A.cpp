#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        int cont = 0;
        int aux;
        int resto = 0;
        int resp = 0;
        for (int i=0; i<n; i++){
            cin >> aux;
            //cout << cont << " " << resp  << endl;
            if (i == 0){
                resto = aux%2;
                cont++;
                continue;
            }
            if (aux%2 == resto){
                cont++;
            }
            else{
                resp += cont-1;
                resto = aux%2;
                cont=1;
            }
        }
        resp += cont-1;
        //cout << "/////////////\n";
        cout << resp << endl;
    }
}