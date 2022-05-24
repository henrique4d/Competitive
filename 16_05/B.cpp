#include <bits/stdc++.h>
using namespace std;

long long modPow(long long base, long long exp, long long mod) {
    // Casos base
    if (base == 0) return 0;
    if (exp == 0) return 1;

    long long step;

    if (exp % 2 == 0) {
        step = modPow(base, exp / 2, mod);
        step = (step * step) % mod;
    }
    else {
        step = base % mod;
        step = (step * modPow(base, exp - 1, mod) % mod) % mod;
    }

    return ((step + mod) % mod);
}

int main(){
    int t;
    cin >> t;
    for (int k =0; k<t; k++){
        long long int n,x;
        cin >> n >> x;
        long long int sum = (x%1000000007)*((long long int )(modPow(2,n,1000000007)-1))%1000000007;

        cout << sum << endl;
    }
}