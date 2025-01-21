#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll x = 0;
    set<ll> s;
    for (int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    }

    if (s.size() == 1){
        cout << *s.begin() << endl;
        return 0;
    }
    ll menor = *s.begin();

    auto it = s.begin();
    it++;
    ll segundo = *it;
    // cout << menor << " " << segundo << endl;
    if (2*menor <= segundo){
        cout << menor << endl;
        return 0;
    }
    else{
        cout << max((ll)1,(menor)/2) << endl;
    }
}