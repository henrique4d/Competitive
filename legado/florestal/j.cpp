#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll cont = 0;
    ll ans = 0;
    for (auto c:s){
        if (c == 'P'){
            cont++;
            if (cont == k){
                ans ++;
                cont = 0;
            }
        }
        else{
            if (cont){
                ans++;
                cont = 0;
            }
        }
    }
    if (cont) ans++;
    cout << ans << endl;
}