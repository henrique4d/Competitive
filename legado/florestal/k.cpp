#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

void gerar(int n){
    if (!n) cout << 0 << " ";
    else{
        gerar(n-1);
        for (int i=1; i<=n; i++){
            cout << i << " ";
        }
        for (int i=n-1; i>=1; i--) cout << i << " ";
        gerar(n-1);
    }
}

int main(){
    ll n;
    cin >> n;
    ll tam = 3;
    for (int i=2; i<=n; i++ ){
        tam = tam*2 + (2*i-1);
    }
    cout << tam << endl;
    gerar(n);
    cout << endl;
    //
}