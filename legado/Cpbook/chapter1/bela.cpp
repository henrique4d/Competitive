#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int pontos = 0;
    char dominant;
    cin >> dominant;

    for (int i=0; i<4*n; i++){
        char value, suit;
        cin >> value >> suit;
        if (value == 'A') pontos += 11;
        else if (value == 'K') pontos += 4;
        else if (value == 'Q') pontos += 3;
        else if (value == 'J' and suit == dominant) pontos += 20;
        else if (value == 'J') pontos += 2;
        else if (value == 'T') pontos += 10;
        else if (value == '9' and suit == dominant) pontos += 14;
    }

    cout << pontos << endl;
}