#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    int x;
    while(q--){
        cin >> x;
        if (x%3){
            cout << "First\n";
        }
        else{
            cout << "Second\n";
        }
    }
}