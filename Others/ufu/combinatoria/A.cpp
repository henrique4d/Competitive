#include <bits/stdc++.h>
using namespace std;

long long int fat(long long int n){
    if (n == 0) return 1;
    return n*fat(n-1);
}



int main(){
    int n;
    cout << fat(20)/(fat(17)) << endl;
    return 0;
    cin >> n;

    for (int i =0; i<n; i++){
        int count[260];
        memset(count,0,sizeof(count));
        string nome;
        cin >> nome;
        if (nome[0] >= 'A' and nome[0] <= 'Z')
            nome[0] += 32;

        long long result = fat(nome.size());
        for (int j=0; j<nome.size(); j++){
            count[nome[j]]++;
        }

        for (int j=0; j<260; j++){
            result/= fat(count[j]);
        }

        cout << result << endl;
    }
}