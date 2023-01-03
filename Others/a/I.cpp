#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int i=0; i<z; i++){
        long long int m,n;
        cin >> m >> n;
        long long int result = pow(2,m);
        
        if (n!=0)
            result--;
        if (m == 1 and n == 0){
            result = 1;
        }
        if (m == 1 and n == 1){
            result = 2;
        }
        cout << result << endl;
    }
}

// 1 0
//  000 001 010 011 100 101 110 111            00 01 10 11