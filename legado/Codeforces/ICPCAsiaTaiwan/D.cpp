#include <bits/stdc++.h>
using namespace std;
int main(){
    long double n;
    cin >> n;
   
    long double pi = 1.0/(n-1.0);

    long double final = pi;

    for (int i=0; i<n-2; i++){
        pi = final;
        pi*=1/(n-i-1);
        final+=pi;
    }

    cout << fixed << setprecision(30) << final << endl;



}