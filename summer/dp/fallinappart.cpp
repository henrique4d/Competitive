#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for (int i=0; i<n; i++){
        cin >> v[i];
        v[i]*=-1;
    }
    sort(v.begin(), v.end());
    
    int alice = 0;
    int bob = 0;
    for (int i=0; i<n; i++){
        if (i&1) bob -= v[i];
        else alice -= v[i];
    }

    cout << alice << " " << bob << endl;
}