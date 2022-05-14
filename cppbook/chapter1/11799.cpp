#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int j=0; j<t; j++){
        int n;
        cin >> n;
        int higher;
        int val;
        cin >> higher;
        for (int i=0; i<n-1; i++){
            cin >> val;
            higher = max(higher,val);
        }
        
        cout << "Case " << j+1 << ": " << higher << endl; 
    }

}