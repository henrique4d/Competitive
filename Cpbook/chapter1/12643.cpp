#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, i,j;
    while(cin >> n){
        cin >> i >> j;
        i--;
        j--;
        int pot_atual = 2;

        for (int cont = 1;true; cont++){
            if (i/pot_atual == j/pot_atual){
                cout << cont << endl;
                break;
            }
            pot_atual*=2;
        }
    }
}