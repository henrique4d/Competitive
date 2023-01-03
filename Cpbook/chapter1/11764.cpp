#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int j=0; j<t; j++){
        int up = 0;
        int down = 0;
        int n;
        cin >> n;
        int val1;
        cin >> val1;
        int val2;
        for (int i=0; i<n-1; i++){
            cin >> val2;
            if (val2 > val1) up++;
            else if (val1 > val2) down++;
            val1 = val2;
        }
        
        cout << "Case " << j+1 << ": " << up << " " << down << endl; 
    }

}