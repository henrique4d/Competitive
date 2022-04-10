#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int saldo = m - n;
    if (saldo == 1){
        printf("Dr. Chaz will have %d piece of chicken left over!\n", abs(saldo));    
    }
    else if (saldo == -1){
        printf("Dr. Chaz needs %d more piece of chicken!\n", abs(saldo));
    }
    else if (saldo > 0){
        printf("Dr. Chaz will have %d pieces of chicken left over!\n", abs(saldo));
    }
    else{
        printf("Dr. Chaz needs %d more pieces of chicken!\n", abs(saldo));
    }
}