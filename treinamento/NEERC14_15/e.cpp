#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,a,b;
    cin >> n;
    vector<ll> urnas;

    bool podemerge = true;
    vector<pair<ll,ll>> trocas;
    
    int contwin = 0; 
    for (int i=0; i<n; i++){
        cin >> a >> b;
        urnas.push_back(a-b);
        if (a > b) contwin++;
    }
    int conturnas = n;

    bool trocar = false;

    for (int i=0; i<n; i++){
        if (contwin > conturnas/2) break;
        if (trocar){
            if ( (urnas[i] + urnas[i-1] > 0 and (urnas[i] <= 0 or urnas[i-1] <= 0)) or (urnas[i] <= 0 and urnas[i-1] <= 0)){
                trocas.push_back({i-1, i});
                conturnas--;
                trocar = false;
                if (contwin > conturnas/2) break;
                continue;
            }
        }
        trocar = true;
    }

    if (contwin <= conturnas/2 ){
        cout << -1 << endl;
        return 0;
    }

    cout << trocas.size() << endl;
    for (int i=0; i<trocas.size(); i++){
        cout << trocas[i].first+1  << " " << trocas[i].second+1  << endl;
    }
}