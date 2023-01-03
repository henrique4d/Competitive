#include <bits/stdc++.h>
using namespace std;
bool compare (char &a, char&b){
    if (a=='0') return false;
    if (b == '0') return true;
    return a>b;

    
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string input;
        cin >> input;
        sort(input.begin(), input.end(), compare);

        cout << input << endl;
    }
}