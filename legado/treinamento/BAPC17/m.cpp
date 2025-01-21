#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n;
ll xzero, yzero, xum, yum;
const ll MAX = 2e5+10;
pair<ll,ll> a[MAX];


bool compare(pair<ll,ll> a, pair<ll,ll> b){
    if (a.first != b.first){
        return a.first < b.first;
    }
    return ( abs(a.second - yzero) < abs(b.second - yzero));
}


struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret,bit[r]);
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], delta);
    }
};




int main(){
    cin >> n;
    cin >> xzero >> yzero >> xum >> yum;
    if (xzero > xum){
        swap(xzero,xum);
        swap(yzero, yum);
    }

    vector<ll> vals;
    vals.push_back(yzero);
    vals.push_back(yum);

    for (int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
        vals.push_back(a[i].second);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    yzero = lower_bound(vals.begin(), vals.end(), yzero) - vals.begin();
    yum = lower_bound(vals.begin(), vals.end(), yum) - vals.begin();
    for (int i=0; i<n; i++){
        a[i].second = lower_bound(vals.begin(), vals.end(), a[i].second) - vals.begin();
    }

    FenwickTree fn(n+100);
    sort(a, a+n, compare);
    ll resp = 0;
    for (int i=0; i<n; i++){
        if (a[i].first < xzero and a[i].first < xum) continue;
        if (a[i].second < yzero and a[i].second < yum) continue;
        if (a[i].first > xzero and a[i].first > xum) continue;
        if (a[i].second > yzero and a[i].second > yum) continue;
        ll aux = fn.sum(abs(a[i].second - yzero));
        fn.add( abs(a[i].second - yzero), aux+1);
        resp = max(resp, aux+1);
    }
    cout << resp << endl;
}