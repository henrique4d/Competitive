#include <bits/stdc++.h>
using namespace std;


long double fat( long double n){
    if (n == 0) return 1;
    if (n == 1) return 1;
    return n*fat(n-1);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        if (val == 0){
            cout << 0 << endl;
            continue;
        }
        long double result = fat(val);
        long long int numdigits = log10(result)+1;
        cout << fixed << setw(numdigits) << setprecision(0) <<  result << endl;
    }
}