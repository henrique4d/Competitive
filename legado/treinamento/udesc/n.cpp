#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int main (){
    optimize;

    ll a,b,c;
    cin >> a >> b >> c;
    if (__gcd(a,b) > c){
        cout << "N\n";
    }
    else cout << "S\n";
}