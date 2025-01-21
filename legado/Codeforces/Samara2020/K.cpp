#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<long long int> v(4);
    for (int i=0; i<4; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    if (v[0] == v[1] == v[2] == v[3]){
        cout << "YES\n";
        return 0;
    }
    if (v[0] == v[1] and v[2] == v[3]){
        cout << "YES\n";
        return 0;    
    }
    if ( v[1] - v[0] == v[3] - v[2]){
        cout << "YES\n";
        return 0;
    }


    cout << "NO\n";
}