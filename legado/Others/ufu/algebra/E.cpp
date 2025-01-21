#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num1 = n;
    int num1aux = num1;
    int num2 = 0;
        

    for (int i=0; i<5; i++){
        //cout << num1 << " ";   
        num1aux = num1;
        int numDigits = log10(num1) + 1;
        int rep1[numDigits];
        int rep2[numDigits];
        
        for (int j=0; j<numDigits; j++){
            rep2[j] = num1aux%10;
            rep1[j] = (int)( num1/pow(10,numDigits-j-1)) %10;
            num1aux/=10;
        }

        bool palindrom = true;
        for (int j=0; j<numDigits; j++){
            if (rep1[j] != rep2[j]) palindrom = false;
        }
        if (palindrom){
            cout << num1 << endl;
            return 0;
        }
        
        num2 = 0;
        for (int j=0; j<numDigits; j++){
            num2 += rep2[j]*pow(10,numDigits - j -1);
        }

        num1 += num2;
    }

    cout << "Nao foi possivel encontrrar um numero capicua com 4 iteracoes!" << endl;
}