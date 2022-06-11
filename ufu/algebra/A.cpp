#include <bits/stdc++.h>
using namespace std;
int main(){
    double dinheiro,preco;
    cin >> dinheiro >> preco;

    int num = dinheiro/preco;

    double troco = dinheiro - num*preco;

    cout << fixed << setprecision(2) << num << " " << troco << endl;
}