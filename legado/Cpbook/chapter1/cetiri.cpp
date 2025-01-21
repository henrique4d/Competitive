#include <bits/stdc++.h>
using namespace std;
int main(){
    int n[3];
    int sum = 0;
    for (int i=0; i<3; i++){
        cin >> n[i];
        sum+= n[i];
    }
    sort(n, n+3);

    int dif1 = n[1] - n[0];
    int dif2 = n[2] - n[1];

    if (dif1 == dif2) cout << n[2] + dif1 << endl;
    else{
        cout << ((2*n[0] + 3*min(dif1,dif2))*2) - sum << endl;
    }
}