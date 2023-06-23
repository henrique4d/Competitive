#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    int n = 100000;
    cout << n << endl;
    for (int i=0; i<n; i++){
        cout << 10 + rand()%2 << " ";
    }
    cout << endl;
}