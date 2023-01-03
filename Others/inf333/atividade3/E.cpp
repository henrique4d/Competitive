#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        string aux1;
        string aux2;

        cin >> aux1;
        long long int num1;
        long long int num2;

        int cont = 0;
        aux2 = aux1;
        for (int i=0; i<aux1.size(); i++){
            aux2[i] = aux1[aux1.size()-1-i];
        }

        while (aux2 != aux1){
            num1 = atoi(aux1.c_str());
            num2 = atoi(aux2.c_str());

            num1+=num2;

            aux1 = to_string(num1);
            aux2 = aux1;
            for (int i=0; i<aux1.size(); i++){
                aux2[i] = aux1[aux1.size()-1-i];
            }
            cont++;   
        }
        cout << cont << " " << num1 << endl;
    }
}