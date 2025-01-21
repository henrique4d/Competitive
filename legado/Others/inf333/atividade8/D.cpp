#include <bits/stdc++.h>
using namespace std;
 
bool colorized(vector<int> neighbor[], string & collor, int pos, char caractere){
    //cout << caractere << endl;
    collor[pos] = caractere;
    for (int i=0; i<neighbor[pos].size(); i++){
        if ( collor[neighbor[pos][i]] == '.'){
            char next;
            if (caractere == 'o') next = 'i';
            else next = 'o';
            //cout << next << endl;
            if (!colorized(neighbor, collor, neighbor[pos][i], next )) return false;
        }
        if (collor[neighbor[pos][i]] == caractere) return false;
    }
 
    return true;
}
int main(){
    int n,m;
    while (cin >> n){
        if (!n) return 0;
        cin >> m;
        string collor="";
        vector<int> neighbor[n];
        for (int i=0; i<n; i++){
            collor.push_back('.');
        }
            
    
        for (int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
         
            neighbor[a].push_back(b);
            neighbor[b].push_back(a);

        }
        // for (int i=0; i<m; i++){
        //     cout << i << ": ";
        //     for (int j=0; j<neighbor[i].size(); j++){
        //         cout << neighbor[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        bool can = true;
        for (int i=0; i<collor.size(); i++){
            if (collor[i] == '.'){
                bool aux = colorized(neighbor, collor, i, 'o');
                if (!aux) can = false;
            }
        }
        
        if (can){
            cout << "BICOLORABLE.\n";
            
        }
        else{
            cout << "NOT BICOLORABLE." << endl;

        }

    }
    
     
}