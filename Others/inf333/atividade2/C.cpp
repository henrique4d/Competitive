#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<int> aux(n);
        for (int i=0; i<n; i++){
            cin >> aux[i];
        }
        map<int,int> used;
        for (int i=0; i<= 9; i++){
            used[i] = -1;
        }

            for (int j=aux[i]+1; j<=9; j++){
        for (int i=n-1; i>=0; i--){
                if (used[j] != -1){
                    swap(aux[i], aux[used[j]] );
                    sort(aux.begin()+i+1, aux.end());
                    goto here;
                }
            }
            
            used[aux[i]] = i;
            if (!i) break;
        }
        cout << -1 << endl;
        continue;
        here:
        for (int i=0; i<n; i++){
            cout << aux[i];
        }
        cout << endl;
    }
}