#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<long long int> v(1e5+10);
    vector<long long int> fat(1e5+10);
    vector<long long int> pot(1e5+10);

    fat[0] = 1;
    fat[1] = 1;
   
    pot[1] = 0;

    for (int i=2; i<1e5+4; i++){
        fat[i] = (i*fat[i-1])%(long long int)(1e9+7);
        pot[i] = i*pot[i-1]%(long long int)(1e9+7);
        pot[i] += ((((i-1)*i)/2)%(long long int)(1e9+7)) *fat[i-1];
        pot[i] %= (long long int)(1e9+7);
    }

    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        long long int val;
        cin >> val;

        long long int part1 = (pot[val]*2)%(long long int)(1e9+7);
        long long int part2 = ( ( ((val*(val-1))/2)%(long long int)(1e9+7)) * fat[val]  )%(long long int)(1e9+7);
        long long int final = (part1 + part2)%(long long int)(1e9+7);
        //cout << val << " " << val*(val-1) << " " << val*(val-1)/2 << " " << part1 << " " << part2 << " " <<  final << endl;
        cout << fixed << setprecision(0) <<  final << endl;
        //cout << fixed << setprecision(0) << 1e9+7 << endl;
    }
}