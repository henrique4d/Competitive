#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
            v[i]*= -1;
        }
        sort(v.begin(), v.end());

        while (v[0]){
            for (int j=1; j<n; j++){
                if (v[j] and v[0]){
                    v[j]++;
                    v[0]++;
                }
            }
            if (v[0]){
                cout << "SAD\n";
                goto here;
            }
            sort(v.begin(), v.end());
        }
        cout << "HAPPY\n";
        here:
        int a;
    }
}