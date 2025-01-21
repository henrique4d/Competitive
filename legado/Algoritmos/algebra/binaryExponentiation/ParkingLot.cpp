#include <bits/stdc++.h>
using namespace std;
int main(){

    long long int n;
    cin >> n;
    long long int classes = 2*n - 2;

    long long int resp = 0;
    resp = n-1;
    
    resp*= classes;

    resp*= pow((classes-1), n-2);
    cout << resp << endl;

}