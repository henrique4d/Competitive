#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main(){
    cin >> n;
    cin >> s;

    int best = 0;
    if (n > 1)
    for (char i='a'; i<='z'; i++){
        for (char j='a'; j<='z'; j++){
            if (i == j)continue;
            string aux;
            for (int k=0; k<n; k++){
                if (s[k] == i or s[k] == j) aux.push_back(s[k]);
            }   
            if (!aux.size()) continue;
            bool pode = true;
            
            for (int k=0; k<aux.size()-1; k++){
                if ( aux[k] == aux[k+1]) pode = false;
            }            
            int auxSize = aux.size();
            if (pode)
                best = max(best, auxSize);
        }
    }

    cout << best << endl;
}