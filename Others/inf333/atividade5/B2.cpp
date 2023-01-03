#include <bits/stdc++.h>
using namespace std;
int main(){
    long double r,n;
    long double pi = acos(-1);
    while (cin >> r >> n){
        if (r == 0){
            cout << "0.0000000000 0.0000000000 0.0000000000\n";
        }
        long double teta = 360/(2*n);
        //cout << teta << endl;
        teta = teta*pi/180;
        long double l = sin(teta)*r*2;
        long double x = l*r/(2*r+l);
        teta = pi-2*teta;
        long double beta = 2*pi/n;



        //cout << fixed << setprecision(10) << x << endl;
        long double h = 2*x*cos(teta/2);
        //cout << beta << " " << tan(beta) << endl;
        long double area_triang = n*x*x/tan(beta/2);// (n-2)*4*x*x*cos(teta/2)*sin(teta/2);
        
        //long double area_triang = 2*x*x*cos(teta/2);
        //cout << fixed << setprecision(10) << area_triang << endl;
        long double area_circ = pi*x*x;
        //cout << fixed << setprecision(10) << area_circ << endl;
        
        
        long double area_sec =  teta*area_circ/(2*pi);
        //cout << teta << " " << 2*teta << " "<< pi-2*teta << " " << (pi-2*teta)/4 << endl;
        //cout << fixed << setprecision(10) << area_sec << " " << teta/(2*pi) << endl;
        

        long double fim = area_triang - n*area_sec;

        long double total = pi*r*r;

        long double borda = total - n*pi*x*x - fim;

        if (r == 1){
            cout << fixed << setprecision(10) << abs(r) << " 0.0000000000 0.0000000000\n";// <<abs(fim) << " " << abs(borda)<< endl;
        }
        cout << fixed << setprecision(10) << abs(x) << " " <<abs(fim) << " " << abs(borda)<< endl;
    }
}