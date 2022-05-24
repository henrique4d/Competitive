#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;
    int count=0;
    long long int aux = n;
    while (aux > 0){
        int div = aux%10;
        aux/=10;
        
        if (div>0 and n%div == 0) count++;
    }

    cout << count;
}