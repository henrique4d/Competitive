#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x1,x2,x3,peso;
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> x1 >> x2 >> x3 >> peso;

        if ( ( (x1 <= 56 and x2 <= 45 and x3 <= 25) or x1 + x2 + x3 <= 125) and peso <=7){
            cout << 1 << endl;
            count++;
        }
        else{
            cout << 0 << endl;
        }
    }

    cout << count << endl;
}