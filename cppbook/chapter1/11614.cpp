#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin >> n;
    for (int i=0; i<n; i++){
        long long int k;
        cin >> k;
        long long int result = ((sqrt(8*k+1)-1)/2);
        cout << result << endl;
    }
}