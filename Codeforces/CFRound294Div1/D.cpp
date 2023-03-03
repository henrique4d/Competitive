#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    unsigned long long int a,b;
    for (int l=0; l<z; l++){
        cin >> a >> b;

        for (long long int shift = 63; shift >=0; shift--){
            unsigned long long int um = 1;
            if ( ((a>>shift)&um) == ((b>>shift)&um)) continue;
            //cout << ((a>>shift)&um) << " " << ((b>>shift)&um) << endl;
            if (((a>>shift)&um) == 0 and ((b>>shift)&um) == um){
                //cout << "here" << endl;
                cout << -1 << endl;
                goto here;
            }
            unsigned long long int resp = 0;
            
            if (((a>>shift)&um) == um and ((b>>shift)&um) == 0){
                //cout << "entrou aqui com o shift de " << shift << endl;                
                for (long long int aux = shift; aux>=0; aux--){
                    //cout << ((a>>aux)&um) << endl;  
                    if (((b>>aux)&um)){
                        //cout << "here2" << endl;
                        cout << -1 << endl;
                        goto here;
                        //fazer o goto
                    }
                    
                    if ( ((a>>aux)&um) == 0){
                        //cout << "atualizando com o aux de " << aux << " que da o valor de " << ((unsigned long long int)1<<aux) << endl;
                        //cout << "resp antes " << resp << endl;
                        resp = (resp|(um<<aux));
                        //cout << "resp depois " << resp << endl;
                        
                    }
                    //cout << resp << endl;
                }
                //cout << "apos o for temos " << resp << endl;
                long double maybe = resp;
                maybe++;
                maybe+=a;
                resp++;
                //cout << "apos o ++ temos " << resp << endl;
                
                resp += a;
                //cout << "apos somar o a temos " << resp << endl;
                //cout << maybe << endl;
                cout << fixed << setprecision(0) << maybe << endl;
                goto here;
            }
        }
        cout << a << endl;
        here:
        int asdfasdf;
        
    }
}