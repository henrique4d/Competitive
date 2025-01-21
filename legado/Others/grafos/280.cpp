#include <bits/stdc++.h>
using namespace std;

void dfs( vector<int> neighbors[], vector<bool> &visited, int pos){
    
    for (int i=0; i<neighbors[pos].size(); i++){
        if (visited[neighbors[pos][i]]) continue;
        visited[neighbors[pos][i]] = true;
        dfs(neighbors, visited, neighbors[pos][i]);
    }
}



int main(){
    int n;
    cin >> n;
    vector<int> neighbors[n];
    vector<bool> visited(n);

    int a;
    int aux;
        
    while(cin >> a){
        if(!a) break;            
        a--;
        while(cin >> aux){
            if (!aux) break;
            aux--;
            neighbors[a].push_back(aux);
        }
    }
    while (cin >> a){
        if (!a) break;
        while (cin >> aux){
//            cout << aux << endl;
            if (!aux) break;
            aux--;
            visited.resize(0);
            visited.resize(n);
            vector<int> resp;
            dfs(neighbors, visited, aux);
            for (int i=0; i<visited.size(); i++){
                if (!visited[i]) resp.push_back(i + 1);
                //cout << visited[i] << " ";
            }
            cout << resp.size();
            if (resp.size()> 0) cout << " ";
            for (int i=0; i<resp.size(); i++){
                cout << resp[i] << " ";
            }
            cout << endl;
        }
    }
}
