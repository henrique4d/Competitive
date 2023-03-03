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
long long int modDiv(long double a, long long int b){
    long double resp = 1;

    if (a >= 100){
            a/= pow(10,((int)log10(a)-2));
        }
    while(b){

        if (b&1){
            resp*=a;
            if (resp >=100){
                resp/= pow(10,((int)log10(resp)-2));
            }
        }
        a*=a;
        if (a >= 100){
            a/= pow(10,((int)log10(a)-2));
        }
        b/=2;
    }
    return resp;
}

int main(){
    int z;
    cin >> z;
    long long int a,b;
    long long int l,r;
   
    for (int h=0;h<z;h++){     
        cin >> a >> b;
        r = modPow(a,b,1000);
        
        l = modDiv(a,b);
       
        cout << setfill('0') <<  fixed << setw(3) << l << "..." << setfill('0') << fixed << setw(3) << r << endl;    
    
    }
}