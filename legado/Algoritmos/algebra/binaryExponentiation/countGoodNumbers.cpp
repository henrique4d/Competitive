#include <bits/stdc++.h>
using namespace std;
long long int modPow(long long int a, long long int b, long long int c){
    long long int resp = 1;
    while(b){
        if (b&1){
            resp*=a;
            resp%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    return resp;
}
int main(){
    long long int n;
    cin >> n;
    

    long long int resp = modPow(5, (n+1)/2, 1e9 + 7);
    resp *= modPow(4, n/2, 1e9+7);
    resp %= (long long int)1e9+7;
    cout << resp << endl;
}