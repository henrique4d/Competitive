#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    while (z--){
        int n;
        cin >> n;
        int pos = 0;
        int neg = 0;
        int aux;
        for (int i=0; i<n; i++){
            cin >> aux;
            if (aux > 0) pos++;
            else neg++;
        }
        int posorig = pos;
        int negorig = neg;

        int cont = 0;
        while (pos){
            cont++;
            if (cont!=1) cout << " ";
            cout << cont;
            pos--;
        }
        while (neg){
            cont--;
            neg--;
            cout << " " << cont;
        }
        cout << endl;

        pos = posorig;
        neg = negorig;

        cont = 0;
        for (int i=0; i<n; i++){
            if (neg and cont>0){
                cont--;
                neg--;
            }
            else{
                cont++;
                pos--;
            }
            if (i) cout << " ";
            cout << cont;
        }
        cout << endl;

    }
}