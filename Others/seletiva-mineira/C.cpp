#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> pares;

    for(int i = 0;i<n;i++){
        long long int aux;
        cin >> aux;
        pares.push_back(make_pair(aux,i));
    }

    sort(pares.begin(), pares.end());

    int result[pares.size()];

    int maiorPos = pares[0].second;
    for (int i=0; i<pares.size(); i++){
        if (pares[i].second > maiorPos){
            result[pares[i].second] = -1;
            maiorPos = pares[i].second;
        }
        else result[pares[i].second] = maiorPos - pares[i].second-1;
    }

    for (int i=0; i<pares.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
/*
    for(int i = 0;i<v.size();i++){
        int indice_mais_nova = -1;
        int ins = -1;
        for(int j = i+1;j<v.size();j++){
            if(v[j] < v[i]) indice_mais_nova = j;
        }
        if (indice_mais_nova !=-1)
        cout << indice_mais_nova - i - 1 << " ";
        else cout << -1 << " ";
    }
    cout << "\n";
    return 0;*/
}