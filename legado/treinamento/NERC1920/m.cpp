#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
using namespace std;
typedef long long ll;
 
const ll MAXN = 2e5+100;
ll a[MAXN];
ll n;
ll contDif[MAXN];
int offset= 100020;


void solve() {
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    ll resp = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (a[i] - a[j] + offset < MAXN) contDif[a[i] - a[j] + offset]++;
        }
        for (int j=i+1; j<n; j++){
            if (a[j] - a[i] + offset < MAXN) resp += contDif[a[j]-a[i] + offset];
        }
        for (int j=0; j<i; j++){
            if (a[i] - a[j] + offset < MAXN) contDif[a[i] - a[j] + offset]--;
        }
    }
    cout << resp << endl;
}
 
int main() {
    optimize;
    int numCases;
    cin >> numCases;
 
    for(int i = 0; i < numCases; i++) solve();
 
    return 0;
}