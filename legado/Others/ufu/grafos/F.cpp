#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int a,b;
    long long int fat[30];
    fat[0] = 1;
    for (int i=1; i<=20; i++){
        fat[i] = i*fat[i-1];
    }

    while(cin >> a >> b){
        long long int result = fat[a] + fat[b];
        cout << result << endl;
    }
}