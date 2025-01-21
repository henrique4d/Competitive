#include <bits/stdc++.h>
using namespace std;
const long long int N = 10000000000000000;

int main(){
    long long int l,k,r;
    cin >> k >> l >> r;

    string a;
    a.reserve(N);

    long long int aux = 0;
    while (a.size() < N){
        a += to_string(aux);
        aux++;
    }


}