#include <bits/stdc++.h>
using namespace std;

// C++ program to demonstrate working of
// extended Euclidean Algorithm
 
// Function for extended Euclidean Algorithm
long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of
    // recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}


int main(){
    long long int n;
    while (cin >> n){
        if (!n) return 0;
        long long int c1,n1,c2,n2;

        cin >> c1 >> n1 >> c2 >> n2;
        long long int v1, v2;

        
        long long int div = gcdExtended(n1,n2, &v1, &v2);
        
        if (n%div){
            cout << "failed" << endl;
            continue;
        }
        v1*=n/div;
        v2*=n/div;
       
        long long int tent1coef = abs(floor((double)v1/(n2/div)));
        long long int tent2coef = abs(floor((double)v2/(n1/div)));
        //cout << tent1coef << " " << tent2coef << endl;
        
        long long int tent1A = v1 + n2/div*tent1coef;
        long long int tent1B = v2 - n1/div*tent1coef;

        while (tent1A < 0){
            tent1A += n2/div;
            tent1B -= n1/div;
        }
        while (tent1B < 0){
            tent1A -= n2/div;
            tent1B += n1/div;
        }
        
        
        long long int tent2A = v1 + n2/div*tent2coef;
        long long int tent2B = v2 - n1/div*tent2coef;

        while (tent2A < 0){
            tent2A += n2/div;
            tent2B -= n1/div;
        }
        while (tent1B < 0){
            tent2A -= n2/div;
            tent2B += n1/div;
        }
        
       
        //cout << tent1A << " " << tent1B << " " << tent2A << " " << tent2B << endl;
        
        long long int resp1 = tent1A*c1 + tent1B*c2;
        long long int resp2 = tent2A*c1 + tent2B*c2;

        if ((tent1A < 0 or tent1B < 0) and (tent2A < 0 or tent2B < 0)){
            cout << "failed" << endl;
            continue;
        }
        if (resp1 <= resp2 and tent1A > 0 and tent1B > 0){
            cout << tent1A << " " << tent1B << endl;
        }
        else if (resp1 >= resp2 and tent2A > 0 and tent2B > 0 ){
            cout << tent2A << " " << tent2B << endl;
        }
    }
}