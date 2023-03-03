#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<string> v(n);

    for (string&s : v) cin >> s;
    int resp = 0;

    for (int j=0; j<m ;j++){
        for (int i=0; i<n-1; i++){
            //cout << i << " " << j << endl;
            if ( v[i+1].substr(0,j+1) < v[i].substr(0,j+1)){
                //cout << v[i+1] << " " << v[i] << endl;
                resp++;
                for (int k=0; k<n; k++){
                    v[k].erase(v[k].begin() + j);
                }
                m--;
                j--;
                break;
            }
        }
    }

    cout << resp << endl;
}