#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    while (cin >> in){
        if (in =="END") return 0;
        if (in == "1"){
            cout << 1 << endl;
            continue;
        }
        int number = in.size();
        int result = 1;
        while (number != 1){
            result++;
            number = log10(number)+1;
        }
        cout << result+1 << endl;
    }
}