#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    ll resp = 1;
    while ((resp<<1) + 1 < n) resp = (resp<<1) + 1;
    cout << resp << endl;
}

int main(){
    int T = 1;

    cin >> T;
    while(T--){
        solve();
    }
}