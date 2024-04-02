#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ll a,b;
    ld r;
    cin >> a >> b >> r;
    ll x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long double resp = ((ld)abs(y2-y1)*r)/b + ((ld)abs(x1-x2)*acos(-1)*min(y1,y2)*r)/(a*b);

    long double resp2 = (ld)y1*r/b + (ld)y2*r/b;

    resp = min(resp, resp2);

    cout << fixed << setprecision(15) << resp << endl;

    
}