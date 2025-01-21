#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(const string & v){
    for (int i=0; i<v.size()/2;i++){
        if (v[i] != v[v.size()-1-i]) return false;
    }
    return true;
}

int main(){
    string in;
    cin >> in;
    int maior = 0;

    for (int i=0; i<in.size(); i++){
        string aux = "";
        for (int j=i; j<in.size(); j++){
            aux.push_back(in[j]);
            //cout << aux << endl;
            if (!checkPalindrome(aux)) maior = max(maior, j-i+1);
        }
    }

    cout << maior << endl;
}