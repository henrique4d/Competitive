#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<pair<int,int>, int>> elefantes;
    elefantes.reserve(1000);
    int a,b;
    int cont = 1;
    while (cin >> a >> b){
        elefantes.push_back(make_pair(make_pair(-a,-b), cont));
        cont++;
    }
    sort(elefantes.begin(), elefantes.end());
    
    vector<pair<int,int>> lis(elefantes.size());
    int maior = 1;
    int start = 0;

    lis[0] = make_pair(1,-1);
    for (int i=1; i<elefantes.size(); i++){
        lis[i] = make_pair(1,-1);
        for (int j=0; j<i; j++){
            if (elefantes[i].first.first > elefantes[j].first.first and elefantes[i].first.second < elefantes[j].first.second){
                if (lis[j].first >= lis[i].first){
                    lis[i].first = lis[j].first+1;
                    lis[i].second = j;
                    if (lis[i].first > maior){
                        maior = lis[i].first;
                        start = i;
                    }
                }
            }
        }
    }
    cout << maior << endl;
    while (start != -1){
        cout << elefantes[start].second << endl;
        start = lis[start].second;
    }
    // for (int i=0; i<elefantes.size(); i++){
    //     cout << elefantes[i].first.first << " " << elefantes[i].first.second << " " << elefantes[i].second << " "<< lis[i].first << " " << lis[i].second << endl;
    // }
}