#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        int n;
        cin >> n;
        int max_dif = INT_MIN;
        int value;
        cin >> value;
        int max_value = value;
        for (int i=1; i<n; i++){
            cin >> value;
            max_dif = max (max_dif, max_value-value);
            max_value = max(max_value,value);
        }
        cout << max_dif << endl;
    }
}