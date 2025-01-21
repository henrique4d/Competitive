#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));
    for (int i=0; i<1e5; i++){
        cout << rand()%10;
    }
    cout << endl;
}