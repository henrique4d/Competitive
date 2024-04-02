#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a[5];
    ll soma = 0;
    ll x;
    for (int i=0; i<5; i++){
        cin >> a[i];
        cin >> x;
        soma += a[i]*x;
    }
    soma/=5;

    ll n, kwf;
    cin >> n >> kwf;

    ll resp = (soma*n)/kwf;
    cout << resp << endl;
}