#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> values(100000);
    while(cin >> n){
        if (!n) return 0;
        int cont = 0;
        values.resize(0);
        values.resize(n);
        for (int i=0; i<n; i++){
            cin >> values[i];
        }

        for (int i=1; i<n-1; i++){
            if (values[i-1] > values[i] and values[i+1] > values[i]) cont++;
            if (values[i-1] < values[i] and values[i+1] < values[i]) cont++;
        }

        if (values[0] > values[n-1] and values[0] > values[1]) cont++;
        if (values[0] < values[n-1] and values[0] < values[1]) cont++;

        if (values[n-1] > values[0] and values[n-1] > values[n-2]) cont++;
        if (values[n-1] < values[0] and values[n-1] < values[n-2]) cont++;

        cout << cont << endl;
    }
}