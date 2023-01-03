#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long int n;
    while (cin >> n){
        if (!n) return 0;
        unsigned long long int aux = 10;
        while (aux >= 10){
            aux = 0;
            while (n > 0){
                aux += n%10;
                n/=10;
            }
            n = aux;
        }
        cout << aux << endl;
    }
}