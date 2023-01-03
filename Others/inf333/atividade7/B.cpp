#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<long long int> v;
    
    int moedas[5] = {1,5,10,25,50};
    while (cin >> n){
        v.resize(0);
        v.resize(8000, 0);

        for (int i=0; i<5;i++){
            v[moedas[i]]++;
            for (int j=1; j<=n; j++){
                if (v[j]) v[j + moedas[i]] += v[j];
            }
        }
        cout << v[n] << endl;
    }

}