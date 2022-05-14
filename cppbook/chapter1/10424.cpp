#include <bits/stdc++.h>
using namespace std;
int main(){
    string nome1;
    string nome2;
    while (getline(cin,nome1)){
        getline(cin,nome2);
        int val1 = 0;
        int val2 = 0;
        int res1 = 0;
        int res2 = 0;
        for (int i=0; i<nome1.size(); i++){
            if (nome1[i] >= 'a' and nome1[i] <='z'){
                val1 += nome1[i] - 'a' + 1;
            }
            if (nome1[i] >= 'A' and nome1[i] <='Z'){
                val1 += nome1[i] - 'A' + 1;
            }
        }
        while (val1 > 0){
            res1+= val1%10;
            val1/=10;
        }
        while(res1>=10){
            val1 = res1;
            res1 = 0;            
            while (val1 > 0){
                res1+= val1%10;
                val1/=10;
            }
        }
        for (int i=0; i<nome2.size(); i++){
            if (nome2[i] >= 'a' and nome2[i] <='z'){
                val2 += nome2[i] - 'a' + 1;
            }
            if (nome2[i] >= 'A' and nome2[i] <='Z'){
                val2 += nome2[i] - 'A' + 1;
            }
        }
            
        while (val2 > 0){
            res2+= val2%10;
            val2/=10;
        }
        
        while(res2>=10){
            val2 = res2;
            res2 = 0;            
            while (val2 > 0){
                res2+= val2%10;
                val2/=10;
            }
        }
        double result = (double)min(res1,res2)*100/max(res1,res2);
        cout << fixed << setprecision(2) << result << " %" << endl;
    }
}