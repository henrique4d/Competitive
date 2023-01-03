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
    long long int a,b,c;  
    while(cin >> a >> b >> c){
        cout << modPow(a,b,c) << endl;
    }
}