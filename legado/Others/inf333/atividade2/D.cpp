#include <bits/stdc++.h>
using namespace std;
string aux;
vector<bool> to_process;

string solve(int pos){
    cout << pos << " " <<  aux[pos] << endl;
    if (pos == aux.size()-1){
        string asdf = "";
        return asdf;
    }
    to_process[pos] = true;
    if (aux[pos] == '('){
        string resp = solve(pos+1);
        /*cout << "vou fazer o for\n";
        for (int i=0; i<aux.size(); i++){
            if(to_process[i] == false ){
                resp += solve(i);
            }
        }*/
        return resp;
    }
    else if (aux[pos] == '+' or aux[pos] == '-' or aux[pos] == '/' or aux[pos] == '*' or aux[pos] == '^'){
        string a = solve(pos+1);
        a.push_back(aux[pos]);
        return a;
    }
    else if (aux[pos] == ')'){
        string asdf = "";
        return asdf;
    }
    else{
        string a;
        a.push_back(aux[pos]);
        a += solve(pos+1);
        return a;
    }
}




int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> aux;
        to_process.resize(0);
        to_process.resize(aux.size(),false);
        string resp = "";
        for (int j=0; j<aux.size(); j++){
            if (to_process[j] == false){
                cout << "chamando\n";
                resp += solve(j);
            };
        }
        cout << resp << endl;
        
    }
    return 0;
}