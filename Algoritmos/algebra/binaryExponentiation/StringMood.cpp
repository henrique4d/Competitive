#include <bits/stdc++.h>
using namespace std;
long long int changeMoodAfterNDays(long long int n){
    
    long long int a = 19;
    long long int b = 6;
    long long int c = 7;
    long long int d = 20;
    long long int h = 1;
    long long int s = 0;
    long long int aOrig = a;
    long long int bOrig = b;
    long long int cOrig = c;
    long long int dOrig = d;
    long long int hOrig = h;
    long long int sOrig = s;


    long double resp = 1;
    while (n){
        if (n&1){
            h = aOrig*hOrig + bOrig*sOrig;
            h %= 1000000007;
            s = cOrig*hOrig + dOrig*sOrig;
            s%= 1000000007;

        }
        a = aOrig*aOrig + bOrig*cOrig;
        a%= 1000000007;
        b = aOrig*bOrig + bOrig *dOrig;
        b%= 1000000007;
        c = cOrig*aOrig + dOrig*cOrig;
        c%= 1000000007;
        d = cOrig*bOrig + dOrig*dOrig;
        d%= 1000000007;
        n/=2;

        aOrig = a;
        bOrig = b;
        cOrig = c;
        dOrig = d;
        hOrig = h;
        sOrig = s;
    }

    return h;
}


int main(){
    long long int n;
    long double p;
    cin >> n;
    long long int resp = changeMoodAfterNDays(n);
    cout << resp << endl;
}