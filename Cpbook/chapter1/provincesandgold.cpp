#include <bits/stdc++.h>
using namespace std;
int main(){
    int g,s,c;
    cin >> g >> s >> c;
    int points = g*3 + s*2 + c;

    if (points >= 8) cout << "Province or ";
    else if (points >= 5) cout << "Duchy or ";
    else if (points >= 2) cout << "Estate or ";

    if (points >= 6) cout << "Gold" << endl;
    else if (points >= 3) cout << "Silver" << endl;
    else cout << "Copper" << endl;
}