#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getDigit1(vector<int> &valores){
    ll val = 0;
    for (int i=0; i<10; i++){
        val += (10-i)*valores[i];
    }
    
    return val;
}

ll getDigit2(vector<int> &valores){
    ll val = 0;
    for (int i=0; i<13; i++){
        if (i&1) val += valores[i]*3;
        else val += valores[i];
    }
    return val;
}

void solve(){
    string s;
    cin >> s;
    int contifen = 0;
    
    vector<int>valores;

    for (int i=0; i<s.size(); i++){
        if (s[i] == 'X' and i != s.size() -1){
            cout << "invalid\n";
            return;    
        }
        if (s[i] == '-' and (i == 0 or i == s.size() -1)){
            cout << "invalid\n";
            return;
        }
        if (s[i] == '-' and i != s.size()-1 and s[i+1] == '-'){
            cout << "invalid\n";
            return;
        }

        if (s[i] == '-' and i != s.size()-2) contifen++;
        else if (s[i] != '-'){
            if (s[i] == 'X'){
                valores.push_back(10);
            }
            else{
                valores.push_back(s[i] - '0');
            }
        }
    }
    
    // for (int i=0; i<10; i++){
    //     cout << i << " " << valores[i] << endl;
    // }
    // cout << getDigit1(valores);
    
    if (valores.size() != 10 or contifen > 2 or getDigit1(valores)%11 != 0){
        cout << "invalid\n";
        return;
    }
    
    valores.pop_back();
    s.pop_back();
    valores.insert(valores.begin(),8);
    valores.insert(valores.begin(),7);
    valores.insert(valores.begin(),9);


    for (int i=0; i<10; i++){
        valores.push_back(i);
        if (getDigit2(valores)%10 == 0){
            cout << "978-" + s + (char)('0'+i) << endl;
            return;
        }
        valores.pop_back();
    }

}

int main(){
    int q;
    cin >> q;
    while (q--){
        solve();
    }
}