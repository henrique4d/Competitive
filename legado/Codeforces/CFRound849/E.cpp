#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        long long int n;
        cin >> n;
        vector<long long int> val(n);
        long long int menor = INT_MAX;
        long long int cont = 0;
        long long int sum = 0;
        for (int i=0; i<n; i++){
            cin >> val[i];
            sum+=abs(val[i]);
            if (val[i] <0) cont++;
            menor = min(menor, abs(val[i]));
        }

        if (cont%2) sum-= menor*2;

        cout << sum << endl;
    }
}