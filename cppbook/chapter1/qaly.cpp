#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double result = 0;
    for (int i=0; i<n; i++){
        double q, t;
        cin >> q >> t;
        result += q*t;
    }
    cout << fixed << setprecision(3) << result << endl;
}