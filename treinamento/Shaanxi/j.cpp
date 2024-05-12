#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

const int MAX = 1e5+10;
pair<ll,ll> a[MAX];
bool mark[MAX];
int n;

void init(){
    for (int i=0; i<n+10; i++){
        mark[i] = false;
    }
}


void solve(){
    cin >> n;
    init();
    for (int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }
    ll resp = 0;
    for (int j=32; j>=0; j--){
        bool lig = true;

        for (int i=0; i<n; i++){
            if (!(a[i].second & ((ll)1<<j)) and !mark[i] ){
                lig = false;
            }

        }

        for (int i=0; i<n; i++){
            if ((a[i].first&((ll)1 << j)) != (a[i].second&((ll)1<<j))){
                if (!lig) mark[i] = true;
                else{
                    a[i].first = ((ll)1<<j);
                }
            }
        }
        if (lig) resp |= ((ll)1<<j);
    }
    cout << resp << endl;
}

int main(){
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
}