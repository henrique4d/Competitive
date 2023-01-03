#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    for (int a=0; a<k; a++){
        string cidade;
        cin >> cidade;
        int area = 0;

        stack<pair<char,int>> pilha;
        for (int i=0; i<cidade.size(); i++){
            char caractere = cidade[i];
            //cout << (caractere == '\\') << endl;
            if (caractere == '\\')
                pilha.push(make_pair(caractere, i));
            else if (caractere == '_') continue;
            else{
                if (!pilha.empty()){
                area += i - pilha.top().second;
                pilha.pop();
                }
            }
        }
        cout << area << endl;
    }
}