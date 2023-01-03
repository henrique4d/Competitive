#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0;l<z;l++){
        int n;
        cin >> n;
        list<long long int> A;
        list<long long int> B;
        long long int aux;
        for (int i=0; i<n; i++){
            cin >> aux;
            A.push_back(aux);
        }
        for (int i=0; i<n; i++){
            cin >> aux;
            B.push_back(aux);
        }
        A.sort();
        B.sort();

        auto ita = A.begin();
        auto itb = B.begin();

        while(true){
            if (ita == A.end() or itb == B.end()) break;
            if (*ita == *itb){
                auto auxa = ita;
                auto auxb = itb;
                auxa++;
                auxb++;

                A.erase(ita);
                B.erase(itb);
                ita = auxa;
                itb = auxb;
            }
            else if (*ita > *itb){
                itb++;
            }
            else if (*itb > *ita){
                ita++;
            }
        }


        int cont = 0;
        for (auto it = A.begin(); it!=A.end(); it++){
            if (*it == 1){
                cont--;
            }
            else if (*it >= 10){
                cont++;
                *it = log10(*it)+1;
            }
        }

        for (auto it = B.begin(); it!=B.end(); it++){
            if (*it == 1){
                cont--;
            }
            else if (*it >= 10){
                cont++;
                *it = log10(*it)+1;
            }
        }

        A.sort();
        B.sort();
        
        ita = A.begin();
        itb = B.begin();

        while(true){
            if (ita == A.end() or itb == B.end()) break;
            if (*ita == *itb){
                auto auxa = ita;
                auto auxb = itb;
                auxa++;
                auxb++;

                A.erase(ita);
                B.erase(itb);
                ita = auxa;
                itb = auxb;
            }
            else if (*ita > *itb){
                itb++;
            }
            else if (*itb > *ita){
                ita++;
            }
        }

        cont += A.size() + B.size();

        cout << cont << endl;

    }
}