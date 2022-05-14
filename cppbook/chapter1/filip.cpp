#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int a2=0, b2=0 ;
    for (int i=0; i<3; i++){
        a2 += (a%10)*pow(10,2-i);
        b2 += (b%10)*pow(10,2-i);
        a/=10;
        b/=10;
    }

    cout << max (a2,b2) << endl;
}