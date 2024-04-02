#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> grau(k+10, 0);
    vector<pair<ll,ll>> a;
    vector<ll> cont(k+5);
    
    set<pair<ll,ll>> app;

    ll u,v;
    for (int i=0; i<n; i++){
        cin >> u >> v;
        if (u < v) swap(u,v);
        if (app.find({u,v}) == app.end()){
            a.push_back({u,v});
        }
        app.insert({u,v});
    }

    for (int i=0; i<a.size(); i++){
        grau[a[i].first]++;
        grau[a[i].second]++;
    
    }

    for (int i=0; i<a.size(); i++){
        if (a[i].first == a[i].second) continue;
        if (grau[a[i].first] > 1) cont[a[i].second]++;
        if (grau[a[i].second] > 1) cont[a[i].first]++;
    }

    for (int i=0; i<k+5; i++){
        if (cont[i] > 2){
            cout << "impossible\n";
            return 0;
        }
    }

    cout << "possible\n";
    
}