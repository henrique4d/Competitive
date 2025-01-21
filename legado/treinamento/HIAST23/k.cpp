#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"


void solve(){
    ll n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<pair<int,int>>>  app(n, vector<pair<int,int>>(30,{-1,-1}));

    for (int i=0; i<n; i++){
        cin >> a[i];
        for (int j=0; j<m; j++){
            if (app[i][a[i][j]-'a'].first == -1) app[i][a[i][j]-'a'].first = j;
            app[i][a[i][j]-'a'].second = j;
        }
    }
    int q;
    cin >> q;
    int l,r;

    while(q--){
        cin >> l >> r;
        l--,r--;
        ll resp = 0;
        // cout << l << " " << r << endl;
        // cout << app[l][0].first << " " << app[l][0].second << endl;
        // cout << app[r][0].first << " " << app[r][0].second << endl;
        // // exit(0);
        for (int i=0; i<27; i++){
            if (app[l][i].first == -1 or app[r][i].first == -1) continue;
            resp += max( (min(app[l][i].second, app[r][i].second) - max(app[l][i].first, app[r][i].first) + 1) , 0);
            // cout << i << " " << resp << endl;
            // exit(0);
        }
        cout << resp << endl;
    
    }
    
}

int main(){
    optimize
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
    }
}