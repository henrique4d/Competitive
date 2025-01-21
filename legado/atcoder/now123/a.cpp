#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a = 0,b = 0;
    int aux;    
    for (int i=0; i<n; i++){
        cin >> aux;
        a += aux;
        cin >> aux;
        b += aux;
    }
    if (a > b){
        cout << "Takahashi\n";
    }
    else if (b > a){
        cout << "Aoki\n";
    }
    else{
        cout << "Draw\n";
    }
}