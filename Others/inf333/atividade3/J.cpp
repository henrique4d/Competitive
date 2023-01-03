#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v(10000000);
    vector<int> gets(10000000);

    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int m,n;
        
        if (l) cout << endl;
        cin >> m >> n;
        v.resize(0);
        v.resize(m);
        gets.resize(0);
        gets.resize(n);

        for (int i=0; i<m; i++){
            cin >> v[i];
        }

        for (int i=0; i<n; i++){
            cin >> gets[i];
        }

        for (int i =0; i<n; i++){
            //cout << gets[i] << " ";
            
            sort(v.begin(),v.begin() + gets[i]);
            /*for (int a=0; a<m; a++){
                cout << v[a] << " ";
            }
            cout << endl;
*/
            cout << v[i] << endl;
        }
    }
}