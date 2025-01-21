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
    long long int a,b;
    while (cin >> a >> b){
        if (!a and !b) return 0;
        long long int resp = 0;
        resp = modPow(a,b,10000007);
        resp += 2*modPow(a-1,b,10000007);
        resp%=10000007;

        resp += modPow(a,a,10000007);
        resp%=10000007;
        resp += 2*modPow(a-1,a-1,10000007);
        resp%=10000007;
        cout << resp << endl;
    }
}

