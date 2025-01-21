#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));

    long long int N = 10000;
    cout << N << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 2 << endl;
    cout << 3 << endl;
    cout << 4 << endl;
    cout << 5 << endl;
    
    for (int i=6; i<N; i++){
        cout << rand()%i << endl;
    }
}