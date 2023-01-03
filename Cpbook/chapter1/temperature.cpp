#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    if (x == 0 and y == 1){
        cout << "ALL GOOD\n";
        return 0;    
    }
    else if (y==1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << fixed << setprecision(9) <<  (double)x/(1-y) << endl;
    }
}