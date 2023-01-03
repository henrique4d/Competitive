#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        int n;
        cin >> n;
        
        int instructions[n];
        int val_atual = 0;
        for (int i=0; i<n; i++){
            string input;
            cin >> input;
            //cout << input << endl;
            if (input == "LEFT") instructions[i] = -1;
            else if (input == "RIGHT") instructions[i] = 1;
            else{
                cin >> input;
                int pos;
                cin >> pos;
                instructions[i] = instructions[pos-1];
            }
            val_atual += instructions[i];
            //cout << val_atual << endl;
        }
        cout << val_atual << endl;

    }
}