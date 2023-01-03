#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<int> values(n);
        for (int i=0; i<n; i++){
            cin >> values[i];
        }
        sort(values.begin(), values.end());
        int meio = values[n/2];
        int final = 0;
        for (int i=0; i<n; i++){
            final += abs(values[i]- meio);
        }    
        cout << final << endl;
    }
}