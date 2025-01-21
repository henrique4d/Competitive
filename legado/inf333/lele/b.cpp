#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e7+10;
map<ll,ll> a;

ll solve(ll v){
    if (a.find(v) != a.end()) return a[v];
    if (v&1) return a[v] = solve(3*v+1)+1;
    else return a[v] = solve(v/2)+1;
}

int main(){
    ll l,r;
    a[1] = 1;
    ll melhor = 0;
    while (cin >> l >> r){
        ll resp = 0;
        for (ll i=min(l,r); i<=max(l,r); i++){
            if (a.find(i) == a.end()){
                solve(i);                
            }
            resp = max(resp, a[i]);

        }
        cout << l << " " << r << " " << resp << endl;
    }   
}