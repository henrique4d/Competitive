#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    vector<int> posicao_ate;
    vector<int> quantidade;

    long long int cont = 0;
    long long int somat = 1;

    for (int j=1; somat <= pow(10,9); j++){
        somat += pow(2,j-1)*j;
        cont++;
        posicao_ate.push_back(somat);
        quantidade.push_back(cont);
    }

    for (int i=0; i<n; i++){
        long long int k;
        cin >> k;
        if (k == 1){
            cout << 0 << endl;
            continue;
        }
        auto a = lower_bound(posicao_ate.begin(), posicao_ate.end(), k);
        long long int index = a-posicao_ate.begin();
        cout << quantidade[index] << endl;        
    }
}