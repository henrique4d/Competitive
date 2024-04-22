#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin >> x;
    for (int i=1; i*i <= x; i++){
        if (x%i == 0){
            if ( i >= (x/i + 1)/2 ){
                cout << 1 << endl;
                return;
            }
        }
        
    }
    cout << 0 << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}