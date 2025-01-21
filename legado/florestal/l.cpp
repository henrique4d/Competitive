#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main(){
    string s;
    bool maiuscula = false;
    bool digito = false;
    bool especial = false;
    cin >> s;
    for (auto x:s){
        if (x >= 'A' and x <= 'Z') maiuscula = true;
        if (x >= '0' and x <= '9') digito = true;
        if (x == '@' or x == '#' or x == '$' or x == '{' or x == '}' or x == '.' ) especial = true;
    }
    bool tam = (s.size()>=8 and s.size() <= 16);

    if (maiuscula and digito and especial and tam) cout << "Valida\n";
    else cout << "Invalida\n";

}