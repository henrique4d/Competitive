#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


ll f(ll x){
    ll resp = 1;

    while (x){
        resp *= (x%10);
        resp %= mod;
        x/=10;
    }

    return resp;
}



void solve(){
    ll a,b;
    cin >> a >> b;
    ll resp = 1;

    for (ll i=0; i<b-a+1 and i<20; i++){
        resp *= f(a+i);
        resp %= mod;
    }
    cout << resp << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}