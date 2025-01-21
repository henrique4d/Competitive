#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;

    vector<pair<pair<ll,ll>, ll>> a(n);
    for (ll i=0; i<n; i++){
        cin >> a[i].first.first;
        cin >> a[i].first.second;
        a[i].first.second *= -1;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    ll limite = 1;
    ll index_best = 0;
    ll potencial = 0;
    vector<ll> resp;

    for (ll i=0; i<n; i++){
        if (a[i].first.first <= limite){
            if (-a[i].first.second > potencial){
                index_best = i;
                potencial = -a[i].first.second;
            }
        }
        else{
            if (a[i].first.first > potencial + 1){
                cout << "NO\n";
                return 0;
            }
            resp.push_back(a[index_best].second);
            limite = potencial + 1;
            i--;
            index_best = -1;
        }
    }

    if (index_best != -1){
        resp.push_back(a[index_best].second);
    }

    if (potencial < m){
        cout << "NO\n";
        return 0;
    }


    cout << "YES\n";
    cout << resp.size() << endl;
    for (ll i=0; i<resp.size(); i++){
        cout << resp[i]+1 << " ";
    }
    cout << endl;

}