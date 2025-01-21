#include <bits/stdc++.h>
using namespace std;

long double changeMoodAfterNDays(long double p, long long int n){
    long double resp = 1;
    while (n){
        if (n&1){
            resp = resp*(1-p) + (1-resp)*p;
        }
        p = 2*p*(1-p);
        n/=2;
    }

    return resp;
}

int main(){
    long long int n;
    long double p;
    cin >> n >> p;
    long double resp = changeMoodAfterNDays(p,n);
    cout << fixed << setprecision(6) << resp << endl;
}