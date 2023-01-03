#include <bits/stdc++.h>
using namespace std;
vector<int> vizinhos[100];


bool dfs(int atual, int parent, int search_for, vector<bool> visitados){
    
    if (atual == search_for) return true;
    visitados[atual] = true;

    bool encontrou = false;

    for ( auto it =vizinhos[atual].begin(); it!=vizinhos[atual].end(); it++){
        if (*it!=parent and !visitados[*it]){
            if (dfs(*it, atual, search_for, visitados)){
                encontrou = true;
            }
        }
    }

    return encontrou;
}


int main(){
    int n, q;
    cin >> n >> q;
    bool havecicle[100];
    memset(havecicle, false, sizeof(havecicle));

    for (int i=0; i<q; i++){
        int a,b,c;
        cin >> a >> b >> c;
        b--;
        c--;
        if (a){
            if (b == c){
                havecicle[b] = true;
                continue;
            }
            vizinhos[b].push_back(c);
            vizinhos[c].push_back(b);
        }
        if (!a){
            if (b == c){
                cout << havecicle[b] << endl;
                continue;
            }
            vector<bool> visitados(100);
            bool encontrou = dfs(b,-1,c, visitados);
            cout << encontrou << endl;
        }
    }

}