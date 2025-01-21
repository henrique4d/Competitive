#include <bits/stdc++.h>
using namespace std;

int maior = 1;



void dfs(vector<list<int>> &neighbors, vector<bool> &visited, int pos ){
    //cout << pos << " " << maior << endl;
    maior++;
    visited[pos] = true;
    for (auto it = neighbors[pos].begin(); it!=neighbors[pos].end(); it++){
        if (visited[*it]) continue;
        visited[*it] = true;
        dfs(neighbors, visited, *it);
    }
}



int main(){
    int z;
    cin >> z;
    string aux;
    vector<list<int>> neighbors(0);
    vector<bool> visited;    
    vector<int> resps;
    int best = -1;


    while (cin >> aux){
        //cout << aux << endl;
        if (aux.size() == 1){
            //cout << "here" << endl;
            int cont = 0;
            for (int i=0; i<neighbors.size(); i++){
                if (!visited[i]){
                    //cout << i << endl;
                    cont++;
                    dfs(neighbors, visited, i);
                    //cout << "fazendo o maximo entre: " << best << " " << maior << endl;
                    best = max(best, maior);
                    
                    maior = 0;
                }
            }
            //cout << "o best atual e " << endl;
            if (best != -1) resps.push_back(cont);
            neighbors.resize(0);
            neighbors.resize(aux[0] - 'A' + 1, list<int>());
            visited.resize(0);
            visited.resize(aux[0] - 'A' + 1, false);
            maior = 0;
            best = -1;
        }
        else{
            neighbors[aux[0] -'A'].push_back(aux[1] - 'A');
            neighbors[aux[1] -'A'].push_back(aux[0] - 'A');

        }

    }
    //cout << "here" << endl;
            int cont = 0;
            for (int i=0; i<neighbors.size(); i++){
                if (!visited[i]){
                    //cout << i << endl;
                    cont++;
                    //cout << "auemntando o cont" << endl;
                    dfs(neighbors, visited, i);
                    //cout << "fazendo o maximo entre: " << best << " " << maior << endl;
                    best = max(best, maior);
                    
                    maior = 0;
                }
            }
    //cout << "o best atual e " << best <<  endl;
            
    if (best != -1) resps.push_back(cont);
    //cout << "//////" << endl;
    for (int i=0; i<resps.size(); i++){
        if (i!=0) cout << endl;
        cout << resps[i] << endl;
    }        

}