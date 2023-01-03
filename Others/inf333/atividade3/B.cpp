#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    map <pair<char,char>, string> opA;
    opA[make_pair('V','V')] = "V";
    opA[make_pair('V','U')] = "U";
    opA[make_pair('V','C')] = "C";
    opA[make_pair('V','D')] = "D";
    opA[make_pair('U','V')] = "U";
    opA[make_pair('U','U')] = "C";
    opA[make_pair('U','C')] = "D";
    opA[make_pair('U','D')] = "VU";
    opA[make_pair('C','V')] = "C";
    opA[make_pair('C','U')] = "D";
    opA[make_pair('C','C')] = "VU";
    opA[make_pair('C','D')] = "UU";
    opA[make_pair('D','V')] = "D";
    opA[make_pair('D','U')] = "VU";
    opA[make_pair('D','C')] = "UU";
    opA[make_pair('D','D')] = "CU";
    cout << "COWCULATIONS OUTPUT\n";
    for (int l=0; l<z; l++){
        string num1;
        string num2;
        cin >> num1 >> num2;
        string gamb1 = "";
        string gamb2 = "";
        for (int i=0; i<8-num1.size(); i++){
            gamb1+= 'V';
        }
        for (int i=0; i<8-num2.size(); i++){
            gamb2+= 'V';
        }
        num1 = gamb1 + num1;
        num2 = gamb2 + num2;

        char operation;
        bool pode = true;
            
        for (int j=0; j<3; j++){
            cin >> operation;
            if (!pode) continue;
            if (operation == 'A'){
                vector<queue<char>> aux(8);

                for (int i=num1.size()-1; i>=0; i--){
                
                    aux[i + 8-num1.size()].push(num1[i]);
                    while(aux[i].size() >= 2){
                        char A = aux[i].front();
                        aux[i].pop();
                        char B = aux[i].front();
                        aux[i].pop();
                        aux[i].push(opA[make_pair(A,B)][0]);
                        if (opA[make_pair(A,B)].size() == 2){
                            if (i == 0){
                                //cout << "NO\n";
                                pode = false;
                            }
                            else{
                                aux[i-1].push(opA[make_pair(A,B)][1]);
                            }
                        }
                    }
                }
                for (int i=num2.size()-1; i >= 0; i--){
                    aux[i + 8 - num2.size()].push(num2[i]);
                    while(aux[i].size() >= 2){
                        char A = aux[i].front();
                        aux[i].pop();
                        char B = aux[i].front();
                        aux[i].pop();
                        aux[i].push(opA[make_pair(A,B)][0]);
                        if (opA[make_pair(A,B)].size() == 2){
                            if (i == 0){
                                //cout << "NO\n";
                                pode = false;
                            }
                            else{
                                aux[i-1].push(opA[make_pair(A,B)][1]);
                            }
                        }
                    }
                }
                
                
                for (int i=7; i>=0; i--){
                    while(aux[i].size() >= 2){
                        char A = aux[i].front();
                        aux[i].pop();
                        char B = aux[i].front();
                        aux[i].pop();
                        aux[i].push(opA[make_pair(A,B)][0]);
                        if (opA[make_pair(A,B)].size() == 2){
                            
                            if (i == 0){
                                //cout << "NO\n";
                                pode = false;
                            }
                            else{
                                aux[i-1].push(opA[make_pair(A,B)][1]);
                            }
                        }
                    }
                }

                num2.clear();
                for (int i=0; i<8; i++){
                    if (!aux[i].empty()){
                        num2.push_back(aux[i].front());
                    }
                }
          
            }
            if (operation == 'R'){
                num2 = "V" + num2.substr(0, num2.size()-1);
            }
            if (operation == 'L'){
                num2 = num2.substr(1, num2.size()) + 'V';
            }
        }
        string result;
        cin >> result;
        string final = "";

        for (int i=0; i<8-num2.size(); i++){
            final.push_back('V');
        }
        final += num2;
       
        if (final == result) cout << "YES\n";
        else cout << "NO\n";
        //cout << final << endl;
    }
    cout << "END OF OUTPUT" << endl;
}