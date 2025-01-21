#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a,b;
    cin >> n;
    cin >> a >> b;

    bool mudando = false;
    int cont = 0;

    
    for (int i=0; i<n; i++){
        if (a[i] != b[i]){
            if (!mudando){
                mudando = true;
                cont++;
            }
        }
        if (a[i] == b[i]){
            mudando = false;
        }
    }
    cout << cont << endl;
}