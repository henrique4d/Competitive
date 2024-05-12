#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+100, 1);
    char t;
    ll l,r;
    while(m--){
        cin >> t >> l >> r;
        if (t == '!') a[l]+=a[r];
        else{
            if (a[l] < a[r]) cout << "<\n";
            else if (a[l] > a[r]) cout << ">\n";
            else cout << "=\n";
        }
        // for (int i=0; i<=n; i++){
        //     cout << i << "-" << a[i] << " ";
        // }
        // cout << endl;
    }

}