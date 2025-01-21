#include <bits/stdc++.h>
using namespace std;
int main(){
    int l;
    cin >> l;
    for (int z=0; z<l; z++){
        int n;
        cin >> n;
        vector<int> values(n);
        int cont = 0;
        for (int i=0; i<n; i++){
            cin >> values[i];
        }
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                if (values[j] < values[i]) cont++;
            }
        }
        
        cout << "Optimal train swapping takes " << cont << " swaps." << endl;
    }
}