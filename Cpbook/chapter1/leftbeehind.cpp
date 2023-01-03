#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while (cin >> a >> b){   
        if (!a and !b) return 0;
        else if (a+b == 13){
            cout << "Never speak again.\n";
        }
        else if (a>b){
            cout << "To the convention.\n";
        }
        else if (a<b){
            cout << "Left beehind.\n";
        }
        else if (a==b){
            cout << "Undecided.\n";
        }
    }
}