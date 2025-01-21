#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const ll MAXN = 1e5+10;
pair<ll,ll> a[MAXN];

int main(){
    ll ans = 0;
    ll sacola;
    ll n;
    cin >> n >> sacola;
    for (int i=0; i<n; i++){
        cin >> a[i].second >> a[i].first;
        a[i].first *= -1;
    }
    sort(a, a+n);
    for (int i=0; i<n; i++){
        ans -= min(sacola, a[i].second) * a[i].first;
        sacola -= min(sacola, a[i].second);
    }
    cout << ans << endl;

}