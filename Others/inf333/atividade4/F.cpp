#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if (!n) return 0;
        multiset<long long int> valores;
        long long int resp = 0;
        for (int i=0; i<n; i++){
            int k;
            cin >> k;
            for (int j=0; j<k; j++){
                long long int aux;
                cin >> aux;
                valores.insert(aux);
            }
            
            resp+= *--valores.end()  - *valores.begin();
            
            valores.erase(valores.begin());
            valores.erase(--valores.end());
        }
        cout << resp << endl;
    }
}