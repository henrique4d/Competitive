#include <bits/stdc++.h>
using namespace std;
long double changeMoodAfterNDays(long double p, long long int n){
    long double a = 1-p;
    long double b = p;
    long double c = p;
    long double d = 1-p;
    long double h = 1;
    long double s = 0;

    long double aOrig = 1-p;
    long double bOrig = p;
    long double cOrig = p;
    long double dOrig = 1-p;
    long double hOrig = 1;
    long double sOrig = 0;


    long double resp = 1;
    while (n){
        if (n&1){
            h = aOrig*hOrig + bOrig*sOrig;
            s = cOrig*hOrig + dOrig*sOrig;
        }
        a = aOrig*aOrig + bOrig*cOrig;
        b = aOrig*bOrig + bOrig *dOrig;
        c = cOrig*aOrig + dOrig*cOrig;
        d = cOrig*bOrig + dOrig*dOrig;
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
    cin >> n >> p;
    long double resp = changeMoodAfterNDays(p,n);
    cout << fixed << setprecision(6) << resp << endl;
}