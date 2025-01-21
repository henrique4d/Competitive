#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 2e5+10;
ll cont[MAXN];
ll n,m,c;

int main(){
    cin >> n >> m >> c;
    ll contfirst = 0;
    ll contsecond = 0;
    for (int i=0; i<n; i++){
        ll a,b;
        cin >> a >> b;
        if (cont[a] < c){
            cont[a]++;
            contfirst++;
        }
        else if (cont[b] < c){
            cont[b]++;
            contsecond++;
        }
    }
    cout << contfirst << " " << contsecond << endl;
}