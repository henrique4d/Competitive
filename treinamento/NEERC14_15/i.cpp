#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    ll resp = 0;
    ll atual = 0;
    sort(a.begin(), a.end());
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    for (int i=0; i<n; i++){
        if (atual + a[i] <= a.back()){
            atual += a[i];
            resp++;
        }
        else break;
    }
    cout << resp+1 << endl;
}