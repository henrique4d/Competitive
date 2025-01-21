#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 10020;
bool know[MAXN][MAXN];
pair<int,string> palavra[MAXN];
int numero[MAXN];
int n,p;
string word[MAXN];

int main(){
    cin >> n >> p;
    
    int contSabeTudo = 0;
    list<int> l;
    for (int i=1; i<=n; i++){
        int lembra;
        cin >> lembra;
        l.push_back(i);
        numero[i] = lembra;
        if (lembra == p) contSabeTudo++;
        
    }
    
    for (int i=1; i<=p; i++){
        cin >> palavra[i].first >> palavra[i].second;
        word[palavra[i].first] = palavra[i].second;
    }

    for (int i=1; i<=n; i++){
        for (int j=0; j<numero[i]; j++){
            know[i][palavra[p-j].first] = true;
        }
    }
    if (contSabeTudo >= 2){
        cout << "-1\n";
        return 0;
    }
    
    int eliminados = 0;
    int atual = 1;
    auto it = l.begin();

    while (true){
        
        if (know[*it][atual]){
            it++;
            atual++;
            if (it == l.end()) it = l.begin();
            if (atual == p+1) atual = 1;
        }
        else{
            eliminados++;
            auto to_erase = it;
            it++;
            if (it == l.end()) it = l.begin();
            l.erase(to_erase);
            if (eliminados != n-1) atual++;
            if (atual == p+1) atual = 1;
        }
        
        if (eliminados == n-1){
            cout << *it << "\n" << word[atual] << endl;
            return 0;
        }
    }
}