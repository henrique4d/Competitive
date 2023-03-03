#include <bits/stdc++.h>
using namespace std;
 
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


int main(){
    long long int n,m,a,k;
    while (cin >> n >> m >> a >> k){
        if (!n and !m and !a  and !k) return 0;
        k+=a;
        // n + c1*m = k + c2*a
        // c2*a - c1*m  = n-k


        int c1,c2;
        int g;
        if (!find_any_solution(-m,a, n-k, c1,c2,g)){
            cout << "Impossible\n";
            continue;
        }
        else if(c1 < 0 and c2 < 0){
            find_any_solution(-m,a,abs(n-k), c1,c2,g);
        }

        cout << /*c1 << " " << c2 << " " << */n + c1*m << endl;
    }
}