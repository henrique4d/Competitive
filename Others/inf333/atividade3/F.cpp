#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a,b;
    while (cin >> a >> b){
        if (!a and !b) return 0;
        int carry = 0;
        int final = 0;
        while (a or b){
            int digA, digB;
            digA = a%10;
            digB = b%10;
            int resp = digA + digB + carry;
            carry = resp/10;
            final += carry;
            a/=10;
            b/=10;
        }
        if (!final){
            cout << "No carry operation.\n";
        }
        else if (final == 1){
            cout << final << " carry operation.\n";

        }
        else{
            cout << final << " carry operations.\n";
        }
    }

   
}