#include <bits/stdc++.h>
using namespace std;

long double fat(long double n){
    if (n == 0) return 1;
    return n*fat(n-1);
}


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        long double materias, pegar, parametro;
        cin >> materias >> pegar >> parametro;

        long double result = fat(materias)/(fat(pegar)*fat(materias-pegar));

        if (result > parametro){
            cout << "Existem mais combinacoes!\n";
        }
        else if (result == parametro){
            cout << "Harry estah correto!\n";
        }
        else{
            cout << "Existem menos combinacoes!\n";
        }
    }
}