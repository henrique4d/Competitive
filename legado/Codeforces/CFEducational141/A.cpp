#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        //cout << n << endl;
        vector<int> v(n);
        for (int &x:v) cin >> x;

        sort(v.begin(), v.end(), greater<int>());
        int maior = v[0];
        int indexcomeco=1;
        int indexfim=n-1;

        if (v[indexcomeco] == maior){
            if (v[indexfim] == maior){
                cout << "NO\n";
            }
            else{
                swap(v[indexcomeco], v[indexfim]);
                cout << "YES\n";
                for (int i=0; i<n; i++){
                    if (i != 0) cout << " ";
                    cout << v[i];
                }
                cout << endl;
            }
            continue;
        }

        cout << "YES\n";
                for (int i=0; i<n; i++){
                    if (i != 0) cout << " ";
                    cout << v[i];
                }
                cout << endl;

    }
}