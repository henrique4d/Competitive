#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    char matrix[5][4*n];

    for (int i=0; i<5; i++){
        for (int j=0; j<4*n; j++){
            cin >> matrix[i][j];
            //cout << matrix[i][j];
        }
        //cout << endl;
    }
    //for (int i=0; i<4*n; i++){
    //    cout << matrix[3][i];
    //}
    //cout << endl;
    //cout << "WTF" << endl;

    for (int i=0; i<n; i++){
        //cout << i << " " << matrix[0][i*4] << endl;
        if (matrix[0][i*4] == '.') cout << 1;
        else if (matrix[3][i*4] == '*') cout << 2;
        else cout << 3;
    }
    cout << endl;
}