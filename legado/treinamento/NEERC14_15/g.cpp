#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 2e5+10;
ll a[MAXN];
ll n,k, valor, tipo;

int main(){
    cin >> n >> k;

    vector<pair<ll,ll>> bom;
    vector<pair<ll,ll>> ruim;
    for (int i=0; i<n; i++){
        cin >> valor >> tipo;
        if (!tipo) ruim.push_back({valor, i});
        else bom.push_back({valor, i});
    }
    sort(ruim.rbegin(), ruim.rend());
    sort(bom.rbegin(), bom.rend());

    ll soma_atual = 0;

    int i = 0;
    int j = 0;

    while (soma_atual < k){
        if (i >= bom.size()){
           soma_atual += ruim[j].first;
           j++; 
        }
        else if (j >= ruim.size()){
            soma_atual += bom[i].first;
            i++;
        }
        else if (bom[i] >= ruim[j]){
            soma_atual += bom[i].first;
            i++;
        }
        else{
            soma_atual += ruim[j].first;
            j++;
        }   
    }
    j--;

    while (j >= 0){
        if (i >= bom.size()) break;
        if (soma_atual - ruim[j].first + bom[i].first >= k){
            soma_atual = soma_atual - ruim[j].first + bom[i].first;
            j--;
            i++;
        }
        else break;
    }

    vector<ll> resp;
    for (int k =0; k<i; k++){
        resp.push_back(bom[k].second);
    }
    for (int k=0; k<=j; k++){
        resp.push_back(ruim[k].second);
    }

    cout << resp.size() << " " << i << endl;

    for (auto x:resp){
        cout << x+1 << " ";
    }
    cout << endl;
}