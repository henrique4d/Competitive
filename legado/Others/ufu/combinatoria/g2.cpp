#include <bits/stdc++.h>
using namespace std;

unsigned long long int fat(unsigned long long int n){
    if (n == 0) return 1;
    return n*fat(n-1);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        unsigned long long int val;
        cin >> val;
        unsigned long long int result;
        result = fat(val);
        cout << result << endl;
    }
}