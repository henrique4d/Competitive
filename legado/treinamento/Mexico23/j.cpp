#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
const ll MAXN = 1e6+10;
ll a[MAXN];
ll sufixSum[MAXN];
ll sufixResp[MAXN];
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) x.begin(), x.end()
#define endl '\n'
#define yes() cout << "YES\n"
#define no() cout << "NO\n"


int main(){
    int n,q;
    optimize;
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (ll i=n-1; i>=0; i--){
        sufixSum[i] = (sufixSum[i+1]+a[i])%mod;
        sufixResp[i] = (sufixResp[i+1] +  ( ( a[i] * sufixSum[i+1] )%mod))%mod;
    }

    ll l,r;
    while(q--){
        cin >> l >> r;
        l--,r--;
        ll resp = sufixResp[l];
        resp -= sufixResp[r+1];
        resp += mod;
        resp %= mod;


        resp -= ( ( (sufixSum[l] - sufixSum[r+1] + mod)%mod)  * (sufixSum[r+1]) )%mod;
        resp += mod;
        resp %= mod;

        cout << resp << endl;
    }

}