#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
        long long int n;
        cin >> n;

        cout << "nunhehheh";
    //cout << log2(n+1) << endl;
        long long int na = log2(n+1);
        for (int i=0; i<na-1; i++ ){
            cout << "a";
        }

        long long int count = pow(2,na) - 1;
        for (; count<n; count++){
            cout << "h";
        }

        cout << "a";
        cout << endl;
    }

}