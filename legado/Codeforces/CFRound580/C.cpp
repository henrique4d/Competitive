#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &x:v){
            cin >> x;
        }
        sort(v.begin(), v.end());
        int dealt = 0;
        long long int needed = 0;
        int cont = 1;
        
        for (int i=0; i<n; i++){
            //cout << v[i] << " " << cont << endl;
            if (v[i] == cont)cont++;

            else if (v[i] > cont){
                needed += v[i] - cont;
                cont++;
            }
        }
        cout << needed << endl;
    }
}