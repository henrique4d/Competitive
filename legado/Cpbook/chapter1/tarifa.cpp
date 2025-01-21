#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    int n;
    cin >> n;
    int result = 0;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        result+=x-val;
    }

    result+=x;
    cout << result << endl;
}