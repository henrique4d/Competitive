#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int v1,v2;
        cin >> v1 >> v2;
        int result = __gcd(v1,v2);
        cout << result << endl;
    }
}