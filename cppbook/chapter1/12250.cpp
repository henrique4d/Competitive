#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    int count = 1;
    while (cin >> in){
        if (in == "#") break;
        else if (in == "HELLO") cout << "Case " << count << ": ENGLISH\n";
        else if (in == "HOLA") cout << "Case " << count << ": SPANISH\n";
        else if (in == "HALLO") cout << "Case " << count << ": GERMAN\n";
        else if (in == "BONJOUR") cout << "Case " << count << ": FRENCH\n";
        else if (in == "CIAO") cout << "Case " << count << ": ITALIAN\n";
        else if (in == "ZDRAVSTVUJTE") cout << "Case " << count << ": RUSSIAN\n";
        else cout << "Case " << count << ": UNKNOWN\n";
        count++;
    }
}