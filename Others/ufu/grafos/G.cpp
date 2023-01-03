#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int mmc = 0;
    int a,b;
    cin >> a >> b;
    mmc = a*b/__gcd(a,b);
    for (int i=0; i<n-2; i++){
        int val;
        cin >> val;
        mmc = val*mmc/__gcd(val,mmc);
    }
    cout << mmc << endl;

}