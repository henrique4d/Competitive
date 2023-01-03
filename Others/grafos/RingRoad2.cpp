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
    cin >> n >> m;
    
    vector<pair<int,int>> v(m);
    string collor="";
    vector<int> neighbor[m];
        

    for (int i=0; i<m; i++){
        collor.push_back('.');
        int a,b;
        cin >> a >> b;
        if (a > b) swap(a,b);
        a--;
        b--;
        for (int j=0; j<m;j++){
            if ( (a < v[j].first and b > v[j].first and b < v[j].second) or (a >v[j].first and a <v[j].second and b>v[j].second) ){
                neighbor[i].push_back(j);
                neighbor[j].push_back(i);
            }
        }
        v[i] = make_pair(a,b);
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
        cout << collor << endl;
    }
    else{
        cout << "Impossible\n";
    }

}