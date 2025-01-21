#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        char aux;
        cin >> aux;
        if (aux == 'c' or aux == 'o' or aux == 'd' or aux == 'e' or aux == 'f' or aux == 'r' or aux == 's' ) cout << "YES\n";
        else cout << "NO\n";
    }
}