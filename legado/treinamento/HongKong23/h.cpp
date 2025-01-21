#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll l,r,b,k;
    cin >> l >> r >> b >> k;
    cout << ((l+b-1)/b)*b*k << endl;
}