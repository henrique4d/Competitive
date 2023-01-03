#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<long long int> v(320);
    v[1] = 1;
    for (int i=2; i<=300; i++){
        v[i] = v[i-1] * (i*i);
    }

    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[10] << endl;
}