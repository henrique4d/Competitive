#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string, vector<string>> kills;



    for (int i=0; i<n; i++){
        string jogador1, jogador2;
        cin >> jogador1 >> jogador2;
        /*for (auto it = kills.begin(); it!= kills.end(); it++){
            for (auto it2 = it->second.begin(); it2!= it->second.end(); it2++){
                if (*it2 == jogador2){
                    //cout << "dando clear - " << " " << jogador1 << " " << jogador2 << endl;
                    for (auto itaux = it->second.begin(); itaux <= it2; itaux++){
                        it->second.erase(itaux);
                    }
                    it->second.clear();
                    break;
                }
            }
        }*/
        for (int i = 0; i < kills[jogador1].size(); i++){
            if (kills[jogador1][i] == jogador2){
                while (kills[jogador1][0] != jogador2 ){
                    kills[jogador1].erase(kills[jogador1].begin());
                }
                kills[jogador1].erase(kills[jogador1].begin());
                i = -1;
            }
        }
        kills[jogador1].push_back(jogador2); 
        //cout << kills[jogador1].size() << endl;
       
        if (kills[jogador1].size() == 5){
            cout << "PENTA KILL!\n";
            return 0;
        }

       
    }

    cout << "SAD:(\n";
}