#include <bits/stdc++.h>
using namespace std;

int main(){

    string a;
    string b;
    cin >> a >> b;
    if (a.size() != b.size()){
        cout << "No\n";
        return 0;
    }
    for (int i=0; i<a.size(); i++){
        if (a[i]%2 != b[i]%2){
            cout << "No\n";
            return 0;
        }    
    }
    
}