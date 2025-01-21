#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll l = -1;
    ll r = 1e9;
    ll m;
    
    while (r-l>1){
        m = l + (r-l)/2;
        if ((m*(m-1))/2 >= a) r = m;
        else l = m;
    }


    ll A = r;

    l = -1;
    r = 1e9;
    while (r-l>1){
        m = l + (r-l)/2;
        if ((m*(m-1))/2 >= d) r = m;
        else l = m;
    }
    ll D = r;
    set<int> posA;
    set<int> posD;

    if (a == 0){
        posA.insert(0);
        posA.insert(1);
    }
    else posA.insert(A);

    if (d == 0){
        posD.insert(0);
        posD.insert(1);
    }
    else posD.insert(D);
    
    for (auto A:posA){
        for (auto D:posD){
            if ((A*(A-1))/2 != a or (D*(D-1))/2 != d ){
                continue;
            }
            
            if (a == 1 and a+b+c+d == 1){
                cout << "00" << endl;
                return;
            }
            if (b == 1 and a+b+c+d == 1){
                cout << "01" << endl;
                return;
            }
            if (c == 1 and a+b+c+d == 1){
                cout << 10 << endl;
                return;
            }
            if (d == 1 and a+b+c+d == 1){
                cout << 11 << endl;
                return;
            }

            if (b+c != A*D){
                continue;
            }

            while (c and c >= A){
                cout << 1;
                c-= A;
                D--;
            }
            bool printou = false;
            while (A--){    
                cout << 0;
                printou = true;
                if (c == A and c){
                    cout << 1;
                    c = -1;
                    D--;
                }
            }
            for (int i=0; i < D; i++){
                cout << 1;
                printou = true;
            }
            if (!printou) cout << 1;
            cout << endl;
            return;
        }
    }
    cout << "impossible\n";


}

int main(){
    int T = 1;
    //cin >> t;
    while (T--) solve();
}