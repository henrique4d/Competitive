#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int automato, n;
    cin >> automato >> n;
    string s;

    cin >> s;
    s = "." + s + ".";

    while (n--){
        string newline = "";
        for (int i=1; i<s.size()-1; i++){
            int val = 0;
            if (s[i-1] == 'X') val += (1<<2);
            if (s[i] == 'X') val += (1<<1);
            if (s[i+1] == 'X') val += (1<<0);

            if (automato&(1<<val)) newline.push_back('X');
            else newline.push_back('.');
        }
        cout << newline << endl;
        s = '.' + newline + '.';
        
    }
}