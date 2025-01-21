#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l = 0; l<z; l++){
        int n;
        cin >> n;
        vector<bool> foi(n+1,false);
        
        int a,b;
        cin >> a >> b;
        int meio = n/2;
        if (a < b){
            if ( !(a <= meio and b>meio)){
            cout << -1 << endl;
            continue;
            }
        }

        if (a > b){
            if ( !(b <= meio and a>meio)){
            cout << -1 << endl;
            continue;
            }
        }

        foi[a] = true;
        foi[b] = true;

        cout << a << " ";
        for (int i=n/2+1; i<=n; i++){
            if (!foi[i]){
                cout << i << " ";
            }
        }

        cout << b << " ";
        for (int i=1; i<=n/2; i++){
            if (!foi[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}