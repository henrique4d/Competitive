#include <bits/stdc++.h>
using namespace std;

long double fat(long double n){
    if (n == 0) return 1;
    if (n == 1) return 1;
    //unsigned long long int result = 0;
    //result%=1000000007;
    return n*fat(n-1);
}

int main(){
    
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int value;
        cin >> value;
        long double result = fat(value);
        long long int numdigits = log10(value) + 1;
        cout << fixed << setw(numdigits) << setprecision(0) << result << endl;
    }
}