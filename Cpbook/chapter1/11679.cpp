#include <bits/stdc++.h>
using namespace std;
int main(){
    int b,n;
    while (cin >> b >> n){
        if (!b and !n) return 0;
        int reserves[b+1];
        for (int i=1; i<=b; i++){
            cin >> reserves[i];
        }
        for (int i=0; i<n; i++){
            int a,b,value;
            cin >> a >> b >> value;
            reserves[a] -= value;
            reserves[b] += value;
        }

        for (int i=1; i<=b; i++){
            if (reserves[i] < 0){
                cout << "N\n";
                goto here;
            }
        }
        cout << "S\n";
        here:
        int asdfalsdkjhf;
    }
}