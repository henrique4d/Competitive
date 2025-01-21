#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    char a,b;
    cin >> a >> b;
    if (a == 'R' and b == 'S'){
        cout << "Jogador 1\n";
        return 0;
    }
    if (a == 'S' and b == 'P'){
        cout << "Jogador 1\n";
        return 0;
    }
    if (a == 'P' and b == 'R'){
        cout << "Jogador 1\n";
        return 0;
    }

    swap(a,b);
    if (a == 'R' and b == 'S'){
        cout << "Jogador 2\n";
        return 0;
    }
    if (a == 'S' and b == 'P'){
        cout << "Jogador 2\n";
        return 0;
    }
    if (a == 'P' and b == 'R'){
        cout << "Jogador 2\n";
        return 0;
    }

    cout << "Empate\n";
}