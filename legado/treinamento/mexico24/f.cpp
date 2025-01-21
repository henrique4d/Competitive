#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int resp = 0;
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        if (x <= k) resp = max(resp, x);
    }
    cout << resp << endl;
}