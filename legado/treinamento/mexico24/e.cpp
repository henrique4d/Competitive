#include <bits/stdc++.h>
using namespace std;
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
typedef long long ll;
#define mod 1000000007

const ll MAXN = 1e5+10;
pair<ll,ll> a[MAXN];

queue<int> q[MAXN];
queue<pair<int,int>> tirados;

int main(){
    optimize;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].first;
        if (a[i].first > n){
            cout << -1 << endl;
            return 0;
        }
        a[i].second = i;
        a[i].first--;
    }
    sort(a, a+n);
    vector<pair<int,int>> resp;
    for (int i=0; i<n; i++){
        int val = a[i].first;
        
        for (int j=val; j>0; j--){
            while (!q[j].empty() and val >= j){
                val -= j;
                resp.push_back({a[i].second,q[j].front()});
                tirados.push({j, q[j].front()});
                q[j].pop();
            }
            j = min(j, val+1);
        }

        if (val){
            cout << -1 << endl;
            return 0;
        }
        q[a[i].first+1].push(a[i].second);

        while (!tirados.empty()){
            q[tirados.front().first].push(tirados.front().second);
            tirados.pop();
        }
    }

    cout << resp.size() << endl;
    for (auto [u,v]:resp){
        cout << u+1 << " " << v+1 << endl;
    }
}