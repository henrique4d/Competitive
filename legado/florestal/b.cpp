#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main(){
    ll n;
    cin >> n;
    ll ans = 1;
    for (int i=0; i<n; i++){
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
}