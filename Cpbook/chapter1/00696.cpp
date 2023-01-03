#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while (cin >> n >> m){
        if (!n and !m) return 0;
        if (!n or !m){
            cout << "0 ";
        }
        else if (n == 1 or m == 1){
            cout << max(n,m) << " ";
        }
        else if (n == 2 or m == 2){
            cout << 4*(max(n,m)/4) + min(2, max(n,m)%4)*2 << " ";
        }
        else
            cout << (n*m+1)/2 << " ";
        printf("knights may be placed on a %d row %d column board.\n", n, m);
    }
}