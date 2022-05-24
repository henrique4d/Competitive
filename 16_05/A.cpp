#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        long long int n;
        long long int x;

        cin >> n >> x;

        long long int diminuir = 0;

        for (int i=0; i<n; i++){
            long long int value;
            cin >> value;
            if (value <= x){
                diminuir += 2*value;
            }
        }

        long long int result = x*(x+1)/2;

        result -= diminuir;

        cout << result << endl;
    }
}