#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 4e5+10;
ll a[MAXN];
ll soma[MAXN];
ll best[MAXN];

int main(){
    ll n, k;
    cin >> n >> k;
    ll soma_final = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        soma[i] = soma[i-1] + a[i];
        best[i] = soma[i] - soma[max(i-k,(ll)0)];
    }
    for (int i=n; i>=1; i--){
        soma_final = max(soma_final, best[i+k] + best[i]);
        best[i] = max(best[i], best[i+1]);
    }
    cout << soma_final << endl;
}