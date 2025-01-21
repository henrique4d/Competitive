#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string val;
        string tipo;
        cin >> val >> tipo;
        int decimal;
        string binario="";
        string hex="";

        if (tipo == "bin"){
            decimal = 0;
            binario = val;
            int pot = 1;
            for (auto it = val.rbegin(); it!=val.rend(); it++){
                if (*it == '1') decimal += pot;
                pot*=2;
            }

            for (int aux = 0; aux < val.size();){

                pot = 1;
                int essaparte = 0;
                for (int j=0; j<4 and j+aux < val.size(); j++){
                    if (val[j+aux] == '1') essaparte += pot;
                    pot *=2;
                }
                if (essaparte <= 9){
                    hex.push_back('0' + essaparte);
                }
                else{
                    hex.push_back('a' + essaparte-10);
                }
                aux += 4;
                }
            }

        if (tipo == "dec"){
            decimal = atoi(val.c_str());
            
            binario;
            while(decimal > 0){
                //cout << decimal << endl;
                if (decimal & 1) binario.push_back('1');
                else binario.push_back('0');
                decimal = decimal >> 1;
            }
            string aux = binario;
            binario = "";
            for (auto it = aux.rbegin(); it!=aux.rend(); it++){
                binario.push_back(*it);
            }
 

                for (int aux = 0; aux < val.size();){
            
                int pot = 1;
                int essaparte = 0;
                for (int j=0; j<4 and j+aux < binario.size(); j++){
                    if (binario[j+aux] == '1') essaparte += pot;
                    pot *=2;
                }
                if (essaparte <= 9){
                    hex.push_back('0' + essaparte);
                }
                else{
                    hex.push_back('a' + essaparte-10);
                }
                aux += 4;
                }
            


        }

        cout << decimal << " " << binario << " " << hex << endl;


    }

}