#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int resp = 0;
    resp = n/2 + 1;

    cout << resp << endl;
    for (int i=1; i<=n; i+=2){
        if (i != 1)
            cout << " ";
        cout << i;
    }
    if (n%2 == 0){
        cout << " " << n;
    }
    cout << endl;
}