#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

set<string> conjunto;

void brute(string s){
    string aux;
    conjunto.insert(s);
    for (int i=0; i<s.size(); i++){
        for (int j = i; j<s.size(); j++){
            aux = s;
            reverse(aux.begin() + i, aux.begin()+j+1);

            for (int k = i; k<=j; k++){
                if (aux[k] == '6') aux[k] = '9';
                else if (aux[k] == '9') aux[k] = '6';
            }
            conjunto.insert(aux);
        }
    }
}

void solve(){
    string s;
    cin >> s;

    ll cont[100];
    for (int i=0; i<20; i++){
        cont[i] = 0;
    }
    for (auto c:s){
        cont[c-'0']++;
    }
    ll n = s.size();
    ll resp = (n*(n+1))/2 + 1;
    
    resp -= ((cont[0]*(cont[0]+1))/2);
    resp -= ((cont[8]*(cont[8]+1))/2);

    resp -= cont[6]*cont[9];
    
    conjunto.clear();
    // brute(s);
    cout << resp << endl;
    // cout << resp << " " << conjunto.size() << endl;

}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}