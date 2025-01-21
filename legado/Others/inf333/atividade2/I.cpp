#include <bits/stdc++.h>
using namespace std;

struct Time{
    string nome;
    int pontos = 0;
    int wins = 0;
    int golsdiff = 0;
    int golsscored = 0;
    int played = 0;
    int ties = 0;
    int loses = 0;
};

bool comparate (Time&A, Time&B){
    if (A.pontos != B.pontos) return A.pontos > B.pontos;
    if (A.wins != B.wins) return A.wins > B.wins;
    if (A.golsdiff != B.golsdiff) return A.golsdiff > B.golsdiff;
    if (A.golsscored != B.golsscored) return A.golsscored > B.golsscored;
    if (A.played != B.played) return A.played < B.played;

    string auxA = A.nome;
    string auxB = B.nome;

    for (int i=0; i<auxA.size(); i++){
        if (auxA[i] >= 'A' and auxA[i] <= 'Z'){
            auxA[i] = auxA[i] - ('A'-'a');
        }
    }
    for (int i=0; i<auxB.size(); i++){
        if (auxB[i] >= 'A' and auxB[i] <= 'Z'){
            auxB[i] = auxB[i] - ('A'-'a');
        }
    }
    
    return auxA < auxB;
}

int main(){
    int z;
    cin >> z;
    cin.ignore();
    for (int l=0; l<z; l++){
        string torname;
        getline(cin, torname);
        if (l) cout << endl;
        cout << torname << endl;
        int n;
        cin >> n;
        cin.ignore();
        map<string, Time> mapa;
        vector<string> times(n);
        vector<Time> v(n);
        for (int i=0; i<n; i++){
            string name;
            getline(cin,name);
            times[i] = name;
            mapa[name].nome = name;
        }

        int k;
        cin >> k;
        cin.ignore();
        for (int i=0; i<k; i++){
            string timeA, timeB;
            string aux;
     
            getline(cin, timeA, '#');
            getline(cin, aux,'@');
            int golsA = atoi(aux.c_str());


            getline(cin, aux,'#');
            int golsB = atoi(aux.c_str());

            getline(cin, timeB);
            //cout << timeA << " " << golsA << " " << timeB << " " << golsB << endl;

            if (golsA > golsB){
                mapa[timeA].pontos += 3;
                mapa[timeA].wins++;
                mapa[timeB].loses++;
            }
            if (golsB > golsA){
                mapa[timeB].pontos += 3;
                mapa[timeB].wins++;
                mapa[timeA].loses++;
            }
            if (golsB == golsA){
                mapa[timeA].pontos += 1;
                mapa[timeB].pontos += 1;
                mapa[timeA].ties++;
                mapa[timeB].ties++;        
            }
            mapa[timeA].golsdiff += golsA-golsB;
            mapa[timeB].golsdiff += golsB-golsA;

            mapa[timeA].golsscored += golsA;
            mapa[timeB].golsscored += golsB;

            mapa[timeA].played++;
            mapa[timeB].played++;
        }
        vector<Time> auxiliar(n);

        for (int i=0; i<n; i++){
            mapa[times[i]].pontos++;
            auxiliar.push_back(mapa[times[i]]);
        }

        sort(auxiliar.begin(), auxiliar.end(), comparate);

        for (int i=0; i<n; i++){
            cout << i+1 << ") " << auxiliar[i].nome << " " << auxiliar[i].pontos-1 << "p, " << auxiliar[i].played << "g (" << auxiliar[i].wins << "-" << auxiliar[i].ties << "-" << auxiliar[i].loses << "), " <<auxiliar[i].golsdiff << "gd (" << auxiliar[i].golsscored << "-" <<  auxiliar[i].golsscored - auxiliar[i].golsdiff << ")" << endl;
        }
    }
}