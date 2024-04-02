#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 1e5+10;
ll a[MAXN];
ll n;

ll lis(){
    vector<ll> l;
    for (int i=0; i<n; i++){
        auto it = upper_bound(l.begin(),l.end(), a[i]);
        if (it == l.end()) l.push_back(a[i]);
        else *it = a[i];
    }
    return l.size();
}


int main(){
    cin >> n;
    vector<pair<char,ll>> cards(n);
    for (int i=0; i<n; i++){
        cin >> cards[i].first;
        cin >> cards[i].second;
    }
    
    vector<char> suits;
    suits.push_back('S');
    suits.push_back('W');
    suits.push_back('E');
    suits.push_back('R');
    vector<ll> suit_value(255);
    
    sort(suits.begin(), suits.end());
    ll x = 0;
    ll best = 0;
    suit_value['C'] = 5;

    do{
        for (int i=0; i<4; i++){
            suit_value[suits[i]] = i;
        }

        for (int i=0; i<n; i++){
            x = suit_value[cards[i].first]*(n+3) + cards[i].second - '0';
            a[i] = x;
        }
        best = max(best, lis());

    }while(next_permutation(suits.begin(), suits.end()));

    cout << n - best << endl;

}