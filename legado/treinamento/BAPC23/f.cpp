#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;

    ll lixo = 0;
    ll atual = 0;
    ll x;

    ll menor = INFLL;
    ll resp = INFLL;

    for (int i=0; i<n; i++){
        cin >> x;
        atual += x;
        if ((atual + m) / m < menor and (i + (atual + m) / m) <= n){
            menor = (atual + m) / m;
            resp = i;
        }
        atual -= m;
        atual = max(atual, (ll)0);
    }
    if (resp == INFLL){
        cout << "impossible\n";
    }
    else
    cout << resp << endl;
}