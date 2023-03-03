#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    int n;
    for (int l=0; l<z; l++){
        cin >> n;
        int aux;
       
        int atual = 0;
        int best = 0;
        int cont = 0;
        int sum = 0;

        for (int i=0; i<n; i++){
            cin >> aux;
            sum += aux;
            atual += aux;
            if (atual > 0) atual = 0;
            best = min(best, atual);
            best = max(best,-2);
        }
        if (best == 0){
            cout << sum-4 << endl;
            continue;
        }
        if (best == -1){
            cout <<sum << endl;
            continue;
        }
        cout << sum - 2*best << endl;
        
    }
}