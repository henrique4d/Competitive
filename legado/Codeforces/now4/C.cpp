#include <bits/stdc++.h>
using namespace std;
int main(){

    int z;
    cin >> z;
    while (z--){
        long long int n;
        cin >> n;
        long long int resp = 26 + 9*(n-4) + (  (n-3)*2*(n-4) )/2;
        cout << resp << endl;
    }
}