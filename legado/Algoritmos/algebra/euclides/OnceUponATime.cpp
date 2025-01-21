#include <bits/stdc++.h>
using namespace std;
 
long long int gcd(long long int a, long long int b, long long int& x, long long int& y) {
    x = 1, y = 0;
    long long int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        long long int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

long long int lcm (long long int a, long long int b) {
    return a / __gcd(a, b) * b;
}
 
int main(){
    long long int n,m,a,k;
    while (cin >> n >> m >> a >> k){
        if (!n and !m and !a  and !k) return 0;
        //k+=a;
        long long int c1,c2;
        long long int divisor = gcd(a,-m,c1,c2);
        
        
        
        if ((n-k)%divisor){
            cout << "Impossible\n";
            continue;
        }
        if (divisor < 0){
            c1*=-1;
            c2*=-1;
            divisor*=-1;
        }


        c1*= (n-k)/divisor;
        c2*= (n-k)/divisor;
 
        long long int d = m/divisor;

        if(c1 <= 0){
            long long int mult = (abs(c1)/d)+1;
            c1 += d*mult;
        }else{
            long long int mult = (c1-1)/d;
            c1 -= d*mult;
        }

        cout << k+a*c1 << endl;
        
    }
}