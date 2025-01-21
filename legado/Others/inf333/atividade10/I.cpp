#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        long long int aux;
        long long int resp = 0;
        for (int i=0; i<n; i++){
            cin >> aux;
            resp = resp^aux;
        }
        if (resp) cout << "Yes\n";
        else cout << "No\n";
    }
}