#include <bits/stdc++.h>
using namespace std;
int main(){
    long double r,n;
    long double pi = acos(-1.0);
    while (cin >> r >> n){
        if (r == 0){
            cout << "0.0000000000 0.0000000000 0.0000000000\n";
            continue;
        }
        long double teta = 360.0/(2.0*n);
        teta = teta*pi/180.0;
        long double l = sin(teta)*r*2.0;
        long double x = l*r/(2.0*r+l);
        teta = pi-2.0*teta;
        long double beta = 2.0*pi/n;

        long double h = 2.0*x*cos(teta/2.0);
        long double area_triang = n*x*x/tan(beta/2.0);
        long double area_circ = pi*x*x;
        
        long double area_sec =  teta*area_circ/(2.0*pi);
        
        long double fim = area_triang - n*area_sec;
        long double total = pi*r*r;
        long double borda = total - n*pi*x*x - fim;
        if (n == 1){
            cout << fixed << setprecision(10) << abs(r) << " 0.0000000000 0.0000000000\n";// <<abs(fim) << " " << abs(borda)<< endl;
            continue;
        }
        cout << fixed << setprecision(10) << fabs(x) << " " << fabs(fim) << " " << fabs(borda)<< endl;
    }
}