#include <bits/stdc++.h>
using namespace std;
int main(){

    int z;
    cin >> z;
    while (z--){
        long long int n;
        cin >> n;
        if (n == 1){
            cout << "1\n";
            continue;
        }
        if (n%2){
            cout << "-1\n";
            continue;
        }

        cout << n << " " << n-1;
        int a = 2;
        int b = n -3;
        for (int i=0; i<(n-2)/2; i++){
            cout << " " << a << " " << b;
            a+=2;
            b-=2;
        }
        cout << endl;

    }
}