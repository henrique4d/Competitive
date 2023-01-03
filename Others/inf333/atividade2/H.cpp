#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<pair<int,int>> tempo_preco(n);
        vector<bool> done(n,false);

        int penalidade_total = 0;
        for (int i=0; i<n; i++){
            cin >> tempo_preco[i].first;
            tempo_preco[i].first++;
            cin >> tempo_preco[i].second;
            penalidade_total += tempo_preco[i].second;
        }
        vector<int> resp;


        for (int i=0; i<n; i++){
            int menor = INT_MAX;
            int index_best;
            for (int j=0; j<n;j++){
                if (done[j]) continue;
                if (tempo_preco[j].first*(penalidade_total-tempo_preco[j].second) <menor ){
                    menor = tempo_preco[j].first*(penalidade_total-tempo_preco[j].second);
                    index_best = j;
                }
            }

            resp.push_back(index_best);
            penalidade_total -= tempo_preco[index_best].second;
            done[index_best] = true;
        }
        if (l != 0) cout << endl;
        for (int i=0; i<n; i++){
            cout << resp[i]+1 << " ";
        }
        cout << endl;

    }
}