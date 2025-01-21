#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    string s;
    stack<pair<ll,ll>> pilhaGlobal[300];

    stack<char> pilha;
    
    for (int i=0; i<n; i++){
        getline(cin,s);
        

        char c;
        int j =0;
        for (int j=0; j<s.size(); j++){
            c = s[j];
            if (c == ' ') continue;
            
            if ( !((c>='a' and c<='z') or c == '}' or c == '{') ){
                continue;
            }
            // cout << "caractere " << c << endl;
            if (c == '}'){
                while(pilha.top() != '{'){
                    pilhaGlobal[pilha.top()].pop();
                    pilha.pop();    
                }
                pilha.pop();
            }
            else if (c == '{'){
                pilha.push('{');
            }
            else{
                // cout << "analizando o caractere " << c  << " " << i << " " << j << endl;
                if (!pilhaGlobal[c].empty()){
                    // cout << i+1 << ":" << j+1 << " - " << pilhaGlobal[c].top().first << " " << pilhaGlobal[c].top().second << endl;
                    cout << i+1 << ":" << j+1 << ": warning: shadowed declaration of " << c << ", the shadowed position is " << pilhaGlobal[c].top().first+1 << ":" << pilhaGlobal[c].top().second+1 << endl;
                }
                pilha.push(c);
                pilhaGlobal[c].push({i,j});
            }
        }
    }
}