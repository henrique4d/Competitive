#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<int> v(n,0);
    int a,b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        a--;
        b--;
        v[a]++;
        v[b]++;
    }

    int cont = 0;
    for (int i=0; i<n; i++){
        if (v[i] == 1) cont++;
    }
    cout << (cont+1)/2 << "\n";

}