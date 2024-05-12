#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX = 30000;
#define mod 1000000007

void solve(){
    ll n,m,k,w;
    cin >> n >> m >> k >> w;
    vector<ll> s1(MAX,0);
    vector<ll> s2(MAX,0);
    ll x = 0;
    s1[0] = 1;
    s2[0] = 1;
    for (ll i=0; i<n; i++){
        cin >> x;
        for (ll j = w; j>=0; j--){
            if (j + x < MAX){
                s1[j+x] += s1[j];
                s1[j+x]%=mod;
            }
            
        }
    }

    for (ll i=0; i<m; i++){
        cin >> x;
        for (ll j = w; j>=0; j--){
            if (j + x < MAX){
                s2[j+x] += s2[j];
                s2[j+x]%=mod;
            }
        }
    }
    // for (int i=1; i<=w; i++){
    //     cout << i << " " << s1[i] << " " << s2[i] << endl;
    // }
    ll resp = 0;
    for (ll i=0; i<=w; i++){
        if ( abs(abs(w-i) - i) <= k){
            resp += (s1[i] * s2[w-i])%mod;
            resp %= mod;
            // cout << i << " " << resp << endl;
        }
        
    }

    cout << resp << endl;

}


int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}