#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    for (int i=0; i<n; i++){
        if (i!= 0) cout << endl;
        string arvore;
        map<string, int> cont;
        int total = 0;
        while (getline(cin, arvore)){
            if (arvore.size() == 0) break;
            cont[arvore]++;
            total++;
        }

        for (auto it = cont.begin(); it!=cont.end(); it++){
            double app = (double) it->second*100/total;
            cout << it->first << " " << fixed <<  setprecision(4) << app << endl;
        }
    }
    
}