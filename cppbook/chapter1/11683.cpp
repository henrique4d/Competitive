#include <bits/stdc++.h>
using namespace std;
int main(){
    int valAtual, n;
    while (cin >> valAtual >> n){
        if (!valAtual) return 0;
    int count = 0;
    
        for (int i=0; i<n; i++){
            int value;
            cin >> value;
            count += max(0, valAtual-value);
            valAtual=value;
        }
        cout << count << endl;
    }
}