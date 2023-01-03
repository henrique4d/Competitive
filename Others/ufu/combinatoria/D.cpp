#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,n;
    long double parametro = pow(26,3) * pow(10,4);

    while (cin >> l){
        cin >> n;

        long double newcombination = pow(26,l)*pow(10,n);

        if (newcombination > parametro){
            cout << "A nova codificacao eh melhor!\n";
        }
        else if (newcombination == parametro){
            cout << "A nova codificacao eh igual!\n";
        }
        else{
            cout << "A nova codificacao eh pior!\n";
        }
    }
}