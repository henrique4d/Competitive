#include <bits/stdc++.h>
using namespace std;

set<int> resp;



void print(vector<int> v){
    for (int i=0; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void eval(vector<int> v, int pos, int atual, int last, vector<int> operacao){
    if (pos == v.size()){
        
        
        for (int i=0; i<(int)operacao.size(); i++){
            if (operacao[i] == 2){
                v[i]*=v[i+1];
                v.erase(v.begin()+ i+1);
                operacao.erase(operacao.begin() + i);
                i--;
            }
        }
        for (int i=0; i<(int)operacao.size(); i++){
            
            if (operacao[i] == 0){
                v[i]+=v[i+1];
                v.erase(v.begin()+ i+1);
                operacao.erase(operacao.begin() + i);
                i--;
            
            }
            
            else if (operacao[i] == 1){
                v[i]-=v[i+1];
                v.erase(v.begin()+ i+1);
                operacao.erase(operacao.begin() + i);
                i--;
            }
        }
        if (v[0] >= 0) resp.insert(v[0]);
    
        return;
    }
    operacao.push_back(0);
    eval(v, pos+1, atual+v[pos], 0, operacao);
    operacao.pop_back();

    operacao.push_back(1);
    eval(v, pos+1, atual-v[pos], 1, operacao);
    operacao.pop_back();
    
    operacao.push_back(2);
    eval(v, pos+1, atual*v[pos], 2, operacao);
    operacao.pop_back();
}



void solve(){

    vector<int> v(4);
    for (int i=0; i<4; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> operacao;
    do{
        eval(v, 1, v[0], 2, operacao);

        vector<int> v2;
        v2.push_back(v[0] * pow(10, to_string(v[3]).size()) + v[3]);
        v2.push_back(v[1]);
        v2.push_back(v[2]);
        sort(v2.begin(), v2.end());
        do{
            eval(v2, 1, v2[0], 2, operacao);

            vector<int> v3;
            v3.push_back(v2[0]* pow(10, to_string(v2[2]).size()) + v2[2]);
            v3.push_back(v2[1]);
            sort(v3.begin(), v3.end());
            do{
                eval(v3, 1, v3[0],2, operacao);
            }while(next_permutation(v3.begin(), v3.end()));

        }while(next_permutation(v2.begin(), v2.end()));


    }while (next_permutation(v.begin(), v.end()));
    

    cout << resp.size() << endl;

    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}