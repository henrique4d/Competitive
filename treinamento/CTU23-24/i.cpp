#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll c,n;
    cin >> c >> n;
    set<ll> s;
    ll x;
    for (int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    }
    for (auto it = s.begin(); it != s.end(); it++){
        if (c%*it == 0 and s.find(c/(*it)) != s.end()){
            cout << *it << " " << c/(*it) << endl;
            return 0;
        }
    }
}