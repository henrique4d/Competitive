#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int cont = 0;
    while (cin >> n){
        cin.ignore();
        vector<bool> horarios(30*60, false);

        for (int i=0; i<n; i++){  
            string aux;
            getline(cin, aux, ':');

            int horas1 = atoi(aux.c_str());
            cin >> aux;
            int min1 = atoi(aux.c_str());

    
            getline(cin, aux, ':');

            int horas2 = atoi(aux.c_str());
            cin >> aux;
            int min2 = atoi(aux.c_str());

            getline(cin, aux);

            int time1 = horas1*60 + min1;
            int time2 = horas2*60 + min2;
            //cout << time1 << " " << time2 << endl;
            horarios[time1] = true;
            for (int i=time1; i<time2; i++){
                horarios[i] = true;
            }
        }
        int cont_atual = 0;
        int comecando_atual = 0;
        int maior = 0;
        int comecando_maior = 0;

        horarios[18*60] = true;
        for (int i=600; i<= 18*60; i++){
            if (horarios[i]){
                if (cont_atual > maior){
                    maior = cont_atual;
                    comecando_maior = comecando_atual;
                }
                cont_atual = 0;
            }
            if (!horarios[i]){
                if (cont_atual == 0){
                    comecando_atual = i;
                }
                cont_atual++;
            }
        }
        cont++;
        //cout << comecando_maior/60 << " " << comecando_maior%60 << " " << maior/60 << " " << maior%60 << endl;
        cout << "Day #" << cont << ": the longest nap starts at " << comecando_maior/60 << ":";
        if (comecando_maior%60 <= 9) cout << 0;
        cout << comecando_maior%60;
        
        cout << " and will last for ";
        
        if (maior/60 > 0){
            cout << maior/60 << " hours and ";
        }
        cout << maior%60;
       
        cout << " minutes.\n";

    }
}