#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        double n;
        cin >> n;
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-= 498;
        int final = n;
        cout << abs((final%100)/10) << endl;
    }
}