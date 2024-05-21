#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,pos,k;
const int MAXN = 1e6+10;
long double transfor[MAXN];

void solve(){
    cin >> n >> pos >> k;

    long double val = 0;
    for (int k = n; k>0; k--){
        transfor[k] = val + k*((long double)1/k);
        transfor[k]/=n;
        val += (long double)1/k;
    }

}

int main(){
    int T = 1;
    while(T--){
        solve();
    }
}