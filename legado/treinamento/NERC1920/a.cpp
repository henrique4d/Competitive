#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,n;
    cin >> a >> b >> n;

    ll resp = (n-a + b-a-1)/(b-a);
    resp += (n-b + b-a-1)/(b-a);

    cout << resp << endl;
}