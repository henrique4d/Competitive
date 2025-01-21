#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    ll ans = 0;

    for (int i=1; i<=15; i++){
        ll aux = pow(5,i);
        ans += n/aux;
    }    
    cout << ans << endl;
}