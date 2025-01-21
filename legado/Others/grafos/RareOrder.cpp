#include <bits/stdc++.h>
using namespace std;
int main(){
    string aux;
    vector<pair<string, bool>> v;
    vector<bool> done(255,false);
    v.push_back(make_pair("-", false));
    while (cin >> aux){
        if (aux == "#") break;
        v.push_back(make_pair(aux,true));
    }
    v.push_back(v.back());
    
    string resp = "";
    for (int j=0; j<=25; j++){
        for (int i=1; i<v.size()-1; i++){        
            //cout << i << " " << j << " " << resp << endl;
            if (v[i].first.size() <= j) v[i].second = false;
            if (v[i].second == false) continue;
            if (!done[v[i].first[j]]){
                resp.push_back(v[i].first[j]);
            }
            done[v[i].first[j]] = true;

            int aux = i;
            if ( (v[i-1].second == true and j < v[i-1].first.size() and v[i].first[j] == v[i-1].first[j]) or (v[i+1].second == true and j < v[i+1].first.size() and v[i].first[j] == v[i+1].first[j])){
            }
            else{
                v[i].second = false;
            }
        }
    }
    cout << resp << endl;
}