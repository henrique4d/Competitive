#include <bits/stdc++.h>
using namespace std;

int flood_fill(vector<string> &m, vector<vector<bool>> &visited, int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    int cont = 0;
    while (!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        cont++;
       
        for (int i=-1; i<2; i++){
            for (int j=-1; j<2; j++){
                if ((i!=0 or j!=0) and m[x+i][y+j] == '1'){
                    q.push(make_pair(x+i, y+j));
                   
                }
            }
        }
    }
    return cont;
}


int main(){
    int z;
    cin >> z;
    string aux;
    cin.ignore();
    getline(cin, aux);
    for (int l=0; l<z; l++){
        if (l) cout << endl;
        vector<string> matriz;
        string padding;
        while (getline(cin, aux)){
            if (aux == "") break;
            aux = '0' + aux + '0';
            if (matriz.size() == 0){
                padding = "";
                for (int i=0; i<aux.size(); i++){
                    padding+='0';
                }
                matriz.push_back(padding);
            }
            matriz.push_back(aux);
        }
        matriz.push_back(padding);
        vector<vector<bool>> used (matriz.size(), vector<bool>(matriz[0].size(), false));
        int best = 0;

        for (int i=0; i<matriz.size(); i++){
            for (int j=0; j<matriz[i].size(); j++){
                if (matriz[i][j] == '1' and !used[i][j]){
                    best = max(best, flood_fill(matriz, used, i, j));
                }
            }
        }
        cout << best << endl;
    }
}