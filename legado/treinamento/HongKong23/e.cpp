#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 1e6+10;
vector<ll> app[MAXN];
ll a[MAXN];
ll n,k;


void solve(){
    cin >> n >> k;
    ll x;
    for (ll i=0; i<n; i++){
        cin >> x;
        a[i] = x;
        app[x].push_back(i);
    }

    vector<pair<pair<ll,ll>, ll>> segments;

    for (ll i=0; i<=1000000; i++){
        for (ll j=0; j + k -1 < app[i].size(); j++){
            if (j+k-1 == app[i].size()-1) segments.push_back({{app[i][j], app[i][j+k-1]},2e9});
            else segments.push_back({{app[i][j], app[i][j+k-1]}, app[i][j+k]});
        }
    }

    sort(segments.begin(), segments.end());

    ll resp = n*(n+1)/2;

    ll lastopen = -1;
    ll lastclose = -1;

    ll danger = 0;
    ll l,r,prox;
    ll lastlook = 0;
    for (auto seg:segments){
        l = seg.first.first;
        r = seg.first.second;
        prox = seg.second;
        if (r <= lastclose ){
            danger += (l - lastopen)*( min(n-lastLo,prox)-r);
            danger += min(lastclose,prox) -r;
            lastopen = l;
            cout << "intervalo - - " << l << " " << r << " " << danger << endl;   
            continue;
        }
        danger += (l-lastopen)*(min(n,prox)-r);
        lastopen = l;
        lastclose = max(lastclose, r);
        cout << "intervalo " << l << " " << r << " " << danger << endl;
    }
    // cout << resp-danger << endl;

    ll respBrute = 0;
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            vector<ll> cont(50,0);
            for (int z=i; z<=j; z++){
                cont[a[z]]++;
            }

            for (int z=0; z<50; z++){
                if (cont[z] == k){
                    cout << "encontrando o intervalo " << i << " " << j << endl;
                    respBrute++;
                    break;
                }
            }
        }
    }
    cout << resp << " " << danger << " " << respBrute << endl;

}

int main(){
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}