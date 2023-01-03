#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int a,b,c;
        cin >> a >> b >> c;
        cout << "Case " << i+1 << ": ";
        if (a>20 or b>20 or c>20) cout << "bad\n";
        else cout << "good\n";
    }
}