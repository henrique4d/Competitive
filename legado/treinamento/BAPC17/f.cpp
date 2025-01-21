#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll Alice = 0, Bob = 0;

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
        a[i]*=-1;
    }
    sort(a.begin(), a.end());
    for (int i=0; i<n; i++){
        if (i&1) Bob -= a[i];
        else Alice -= a[i];
    }
    cout << Alice << " " << Bob << endl;
}