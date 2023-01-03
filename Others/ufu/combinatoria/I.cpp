#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        int result = val*(val-1)/2 + 4;
        cout << result << endl;
    }
}