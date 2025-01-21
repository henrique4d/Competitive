#include <bits/stdc++.h>
using namespace std;

long long int modPow(long long int a, long long int b, long long int c){
    long long int resp = 1;
    while(b){
        if (b&1){
            resp*=a;
            resp%=c;
        }
        a*=a;
        a%=c;
        b/=2;
    }
    return resp;
}

int main(){
    int z;
    cin >> z;
    long long int a,b; 
    
    for (int l=0; l<z; l++){
        cin >> a;
        if (a == 0){
            cout << 0 << endl;
            continue;
        }
        if (a == 0 or a == 1){
            cout << 1 << endl;
            continue;
        }
        if (a == 2){
            cout << 2 << endl;
            continue;
        }
        if (a == 3){
            cout << 3 << endl;
            continue;
        }

        if (a == 4){
            cout << 4 << endl;
            continue;
        }
        long long int base = 3;
        //cout << a << " " << base << " " << a/base << endl;
        long long int power = a/base;
        long long int resp = 1;
        
        if (a%base != 0){
            if (a%base == 1){
                power--;
                resp = a%base + base;
            }
            else{
                resp = a%base;
            }
            
        }
        resp %=1000000007;
  
        //cout << resp << endl;
      
        //cout << resp << " " << base << " " << power << endl;
        resp *= modPow(base,power,1000000007);
        resp %=1000000007;
        cout << resp << endl;

    }
    
}