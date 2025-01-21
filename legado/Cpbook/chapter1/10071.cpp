#include <bits/stdc++.h>
using namespace std;
int main(){
    double v, t;
    while (cin >> v >> t){
        if (!t){
            cout << 0 << endl;
            continue;
        }
        double a = v/t;
        t*=2;
        double result = a*t*t/2;
        cout << result << endl;
    }
}