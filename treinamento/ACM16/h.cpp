#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll n,k;
    cin >> n >> k;
    k++;
    string s;
    cin >> s;
    ll cont = 0;
    for (auto c:s){
        if (c == '0') cont++;
        else cont = 0;
        if (cont >= k){
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}


int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}