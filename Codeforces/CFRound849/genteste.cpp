#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 200000;
    cout << n << " " << n << endl;
    for (int i=0; i<n; i++){
        cout << rand()%10000000 << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++){
        if (rand()%2){
            cout << "1 1 10\n";
        }
        else{
            cout << "2 " << rand()%200000 << endl;
        }
    }
}