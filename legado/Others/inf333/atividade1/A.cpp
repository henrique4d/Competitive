#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    vector<int> pos(1000009);
    vector<int> portal(1000);
    for (int z=0; z<k; z++){
        int players, Nportal, dados;
        cin >> players >> Nportal >> dados;
        pos.resize(0);
        pos.resize(players, 1);
        portal.resize(0);
        portal.resize(Nportal, 0);
      
        
        for (int i=0; i<Nportal; i++){
            int a,b;
            cin >> a >> b;
            portal[a] = b;
        }
        int atual = 0;
        bool acabou = false;

        for (int i=0; i<dados; i++){
            int value;
            cin >> value;
            if (acabou) continue;
            pos[atual] += value;
            if (pos[atual] >= 100){
                acabou = true;
                pos[atual] = 100;
            }
            if (portal[pos[atual]] != 0){
                pos[atual] = portal[pos[atual]];
            }
            atual++;
            if (atual == players) atual = 0;
        }

        for (int i=0; i<players; i++){
            cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
        }



    }
}