#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while (cin >> a >> b){
        if (!a and !b) return 0;
        int cont = 0;
        if (a > b) swap(a,b);
    
        if (b%a == 0){
            cout << "Stan wins\n";
            
            continue;
        }
        long double goldenRatio = (sqrt(5)+1)/2;
        long double aux = (double)b/a;
        if (aux >=goldenRatio){
            cout << "Stan wins\n";
           
            
            continue;
        }

        cout << "Ollie wins\n";
        
    }
}