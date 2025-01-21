#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> resp;
vector<int> sortAux;

bool compare(int a, int b){
    return sortAux[a] < sortAux[b];
}

void avaliaIntervalo(int a, int b){
    char symbol;
    int pos = 0;
    int parametro = v[a+1];
    for (int i=a+1; i<=b-1; i++){
        cout << "? " << parametro << " " << v[i] << endl;
        cin >> symbol;
        if (symbol == '='){
            pos = i;
            break;
        }
    }
    swap(v[pos], v[parametro]);
    for (int i=a+1; i<=b-1; i++){
        if (i == parametro){
            sortAux[i] = 0;
        }
        cout << "? " << v[i] << " " << v[parametro] << endl;
        cin >> symbol;
        if (symbol == '<'){
            sortAux[i] = -1;
        }
        else sortAux[i] = 1;
    }

    stable_sort(v.begin()+a+1, v.begin()+b+1, compare);
}


int main(){
    int n;
    cin >> n;
    
    v.resize(n+2);
    resp.resize(n+2);
    sortAux.resize(n+2);

    for (int i=0; i<n+1; i++){
        v[i] = i;
        resp[i] = i;
    }

    vector<int> checkpoints;
    checkpoints.push_back(0);
    checkpoints.push_back(n+1);
    avaliaIntervalo(0,6);
    for (int i=0; i<n+2; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}