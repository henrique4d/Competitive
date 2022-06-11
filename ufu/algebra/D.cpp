#include <bits/stdc++.h>
using namespace std;
int main(){
    int count = 0;
    int value;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> value;
        count += max(0, value -3);
    }

    cout << count << endl;
}