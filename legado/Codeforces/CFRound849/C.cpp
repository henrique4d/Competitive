#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        string path;
        cin >> path;
        int cont = 0;
        for (int i=0; i<n/2; i++){
            if (path[i] != path[n-1-i]) cont++;
            else break;
        }
        cout << n - 2*cont << endl;   
    }
}