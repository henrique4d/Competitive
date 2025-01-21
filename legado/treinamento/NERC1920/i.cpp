#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
using namespace std;
typedef long long ll;

const ll MAXN = 1010;
ll x[MAXN];
ll y[MAXN];
ll h[MAXN];
ll n;


void solve() {
    cin >> n;
    for (ll i=0; i<n; i++){
        cin >> x[i] >> y[i] >> h[i];
    }

    ll xLeft = 100000000;
    ll xRigth = -100000000;

    ll yLeft = 100000000;
    ll yRigth = -100000000;

    for (int i=0; i<n; i++){
        xLeft = min(xLeft, x[i] - h[i]);
        xRigth = max(xRigth, x[i] + h[i]);
        yLeft = min(yLeft, y[i] - h[i]);
        yRigth = max(yRigth, y[i] + h[i]);
    }

    ll xCentro = xLeft + (xRigth-xLeft)/2;
    ll yCentro = yLeft + (yRigth-yLeft)/2;

    ll altura = 0;
    for (ll i=0; i<n; i++){
        altura = max(altura, h[i] + abs(x[i] - xCentro));
        altura = max(altura, h[i] + abs(y[i] - yCentro));
    }
    cout <<xCentro << " " << yCentro << " " << altura << endl;
}
 
int main() {
    optimize;
    int numCases = 1;
    // cin >> numCases;
 
    for(int i = 0; i < numCases; i++) solve();
 
    return 0;
}