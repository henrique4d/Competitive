#include <bits/stdc++.h>
using namespace std;
int main(){
    int left, right;
    cin >> left >> right;
    if (!left and !right) {
        cout << "Not a moose" << endl;
        return 0;
    }
    if (left == right) cout << "Even ";
    else cout << "Odd ";
    cout << max(left,right)*2 << endl;
}