#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int j=0; j<t; j++){
        int n;
        cin >> n;
        int val1;
        cin >> val1;
        int val2;
        int pos = -1;
        for (int i=0; i<n-1; i++){
            cin >> val2;
            if (val1+1 != val2 and pos == -1){
                pos = i+2;
            }
            val1 = val2;
        }    
        cout << pos << endl; 
    }

}