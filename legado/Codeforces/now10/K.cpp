#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;

    queue<int> comida;
    queue<int> pessoas;
    int aux;
    for (int i=0; i<n; i++){
        cin >> aux;
        pessoas.push(aux);
    }
    for (int i=0; i<m; i++){
        cin >> aux;
        comida.push(aux);
    }

    int resp = 0;
    int soup = 0;
    soup = comida.front();
    comida.pop();
    while (!pessoas.empty()){
        if (soup >= pessoas.front()){
            soup -= pessoas.front();
            pessoas.pop();
        }
        else{
            resp+=soup;
            soup = comida.front();
            comida.pop();
            
        }
    }
    resp+=soup;
    
    while( !comida.empty())
    {
        resp+= comida.front();
        comida.pop();
    }
    cout << resp << endl;
}