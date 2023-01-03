#include <bits/stdc++.h>
using namespace std;


int main(){
    long double altura, largura, angulo;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> largura >> altura >> angulo;
        long double pi = acos(-1);
       
        angulo = angulo*pi/180;
        long double A = largura/cos(angulo);
        //cout << largura << " " << angulo << " " << cos(angulo) << " " << largura*sqrt(2) << " " << A << endl;
        //cout << angulo << " " << cos(angulo) << endl;
        //cout << A << endl;

    

        //cos aangulo = largura/hipotenusa
        //hipotenusa = largura / cos angulo
        long double altura_viajada = sin(angulo)*A;
        
        long double ponto2 = altura_viajada/(2*altura);
        
        ponto2 -= (int) ponto2;
        ponto2*= 2*altura;
        if (ponto2 > altura){
            ponto2 = 2*altura - ponto2;
        }
        
        //cout << altura_viajada << " "<< ponto2 << endl;
        //cout << largura << " " << ponto2 << endl;
        long double B = sqrt( largura*largura + ponto2*ponto2 );
        long double ratio = A/B;

        ratio = round( ratio * 1000.0 ) / 1000.0;

        //cout << A << " " << B << " " << ratio << endl;
        //cout << A << " " << altura_viajada << " " << ponto2 << endl;
        cout << fixed << setprecision(3) << ratio << endl;
/*


        
  
        
        cout << altura_viajada << " " << ponto2 << endl;
        cout << A << " " << B << " " << ratio;// << " " << altura_viajada << ponto2 << endl;*/
    }
}