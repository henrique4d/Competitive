#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }    

    set<ll> s;
    set<ll> s2;

    set<ll> resp;

    for (int i=n-1; i>=0; i--){
        for (auto it = s2.begin(); it!=s2.end(); it++){
            s.insert(__gcd(*it, a[i]));
            resp.insert(__gcd(*it, a[i]));
        }
        s.insert(a[i]);
        resp.insert(a[i]);
        s2 = s;
        s.clear();
    }
    cout << resp.size() << endl;
}