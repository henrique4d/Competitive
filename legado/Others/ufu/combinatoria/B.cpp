#include <bits/stdc++.h>
using namespace std;

long long int fat(long long int n){
    if (n == 0) return 1;
    return n*fat(n-1);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        long long int result;
        result = fat(val)/fat(val-3);

        cout << result << endl;
    }
}