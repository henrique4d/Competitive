#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char tab[30][30];

int main(){
    for (int i=0; i<7; i++){
        for (int j=0; j<24; j++){
            cin >> tab[i][j];
        }
    }

    ll best = 0;
    ll d,h;
    cin >> d >> h;
    vector<ll> tempos;
    ll cont = 0;
    ll respAtual = 0;

    for (int i=0; i<(1<<8); i++){
        if (__builtin_popcount(i) == d){
            tempos.clear();
            respAtual = 0;
            for (int j=0; j<24; j++){
                cont = 0;
                for (int dia = 0; dia <7; dia++){
                    if ( (i&(1<<dia)) and tab[dia][j] == '.') cont++;
                }
                tempos.push_back(cont);
            }
            sort(tempos.rbegin(), tempos.rend());
            for (int j =0; j < h; j++){
                respAtual += tempos[j];
            }

            best = max(best, respAtual);
        }
    }
    cout << fixed << setprecision(15) <<  (long double) best/(d*h) << endl;

}