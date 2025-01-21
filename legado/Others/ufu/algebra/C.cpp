#include <bits/stdc++.h>
using namespace std;
int main(){
    int gols1, gols2, pomo;

    cin >> gols1 >> gols2 >> pomo;

    int pont1 = gols1*10;
    int pont2 = gols2*10;

    if (pomo == 1) pont1 += 150;
    else pont2 += 150;
    cout << pont1 << " x " << pont2 << endl;
        

    if (pont1 == pont2) cout << "Nao houve campeao!\n";
    else{
        cout << "Ganhador: Time";
        if (pont1 > pont2) cout << 1;
        else cout << 2;
        cout << "!\n";
    }
    return 0;
}