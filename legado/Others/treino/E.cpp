#include <bits/stdc++.h>
using namespace std;

long long int fat(int n){
    long long int result = 1;
    for (long long int i = 2; i <=n; i++){
        result*=i;
        result%=1000000007;
    }
    return result;
}

long long int modPow(long long int base, long long exp, long long mod) {
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

long long int power( long long int x,
                                  long long int y, long long int p)
{
    long long int  res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
long long int modInverse(long long int n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
long long int nCrModPFermat(long long int n,
                                 int r, int p, long long int *fac)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}




int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    long long int  fatorial[m+2];
    memset(fatorial,1, sizeof(fatorial));
    fatorial[0] = 1;
    for (long long int i = 1; i<m+2; i++){
        fatorial[i] = (fatorial[i-1]*i)%1000000007;
        
    }
    
    int fator = 1;
    if (k%2==0) fator = -1;
    long long int result = 0;
    
    
    for (int i=1; i<=k; i++){
        result += fator * (nCrModPFermat(m,i,1000000007, fatorial) * modPow(i,n,1000000007))%1000000007;
        fator*=-1;
    }
    while (result <= 0) result += 1000000007;
    cout << result << endl;
    }