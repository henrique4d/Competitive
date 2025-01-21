#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a,b,c;
    cin >> n;
    cin >> a >> b >> c;

    string resp = a;
    for (int i=0; i<n; i++){
        if (b[i] == c[i]) resp[i] = b[i];
    }
    cout << resp << endl;
}