#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x, y, z;
};

int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        bool sinal = 1;
        char atual = 'x';
        for (int i=0; i<n-1; i++){
            string in;
            cin >> in;
            if (in == "No") continue;
            else if (atual == 'x'){
                atual = in[1];
                if (in[0] == '-') sinal = !sinal;
            }
            else if (atual == in[1]){
                atual = 'x';
                sinal = !sinal;
                if (in[0] == '-') sinal = !sinal;
            }
        }

        if (sinal) cout << "+";
        else cout << "-";
        cout << atual << endl;

    }
}