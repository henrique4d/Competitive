#include<bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l = 0; l<z; l++){
        int a,b,c;
        cin >> a >> b >> c;
        bool escreve = false;
        int contA = 0;
        int contAy = 0;
        string aux;
        for (int i=0; i<a; i++){
            cin >> aux;
            for (int j=0; j<aux.size(); j++){
                if (tolower(aux[j]) == 'a' or tolower(aux[j]) == 'e' or tolower(aux[j]) == 'i' or tolower(aux[j]) == 'o' or tolower(aux[j]) == 'u'){
                    contA++;
                }
                if (tolower(aux[j]) == 'y') contAy++;
            }
        }
        if ( (contA > 5 or contA+contAy <5) and !escreve ){
            cout << "NO\n";
            escreve = true;
            //continue;
        }



        int contB = 0;
        int contBy = 0;
        for (int i=0; i<b; i++){
            cin >> aux;
            for (int j=0; j<aux.size(); j++){
                if (tolower(aux[j]) == 'a' or tolower(aux[j]) == 'e' or tolower(aux[j]) == 'i' or tolower(aux[j]) == 'o' or tolower(aux[j]) == 'u'){
                    contB++;
                }
                if (tolower(aux[j]) == 'y') contBy++;
            }
        }
        if ( (contB > 7 or contB+contBy <7)  and !escreve ){
            cout << "NO\n";
            escreve = true;
        }



        int contC = 0;
        int contCy = 0;
        for (int i=0; i<c; i++){
            cin >> aux;
            for (int j=0; j<aux.size(); j++){
                if (tolower(aux[j]) == 'a' or tolower(aux[j]) == 'e' or tolower(aux[j]) == 'i' or tolower(aux[j]) == 'o' or tolower(aux[j]) == 'u'){
                    contC++;
                }
                if (tolower(aux[j]) == 'y') contCy++;
            }
        }
        if ( (contC >5 or contC+contCy <5)  and !escreve ){
            cout << "NO\n";
            escreve = true;
        }
        
        if (!escreve){
            cout << "YES\n";
        }
        

    }
}