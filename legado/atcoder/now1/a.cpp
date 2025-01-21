#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int maior = INT_MIN;
    int primeiro;
    cin >> primeiro;
    int aux;
    for (int i=1; i<n; i++){
        cin >> aux;
        maior = max(maior, aux);
    }
    if (maior == INT_MIN) cout << 0 << endl;
    else cout << max(maior-primeiro+1,0) << endl;
}