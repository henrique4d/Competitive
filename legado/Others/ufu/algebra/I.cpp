#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int value;
        cin >> value;
        double sizeaux = log2(value);
        int size = ceil(sizeaux) + 1;
        for (int j=0; j<size; j++){
            if (value >> j & 1) cout << j << " ";
        }

    cout << endl;
    }
    
}