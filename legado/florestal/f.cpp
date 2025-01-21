#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

const ll MAXN = 1e3+10;
pair<ll,ll> a[MAXN];

int main(){
    ll n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll q;
    cin >> q;
    while (q--){
        ll x,y;
        cin >> x >> y;
        ll ans = 0;
        ll menor_dist = 1e15;
        for (int i=0; i<n; i++){
            if ( (x - a[i].first)*(x - a[i].first) + (y - a[i].second)*(y - a[i].second) < menor_dist ){
                menor_dist = (x - a[i].first)*(x - a[i].first) + (y - a[i].second)*(y - a[i].second);
                ans = i;
            }
        
        }
        cout << ans << endl;
    }
}