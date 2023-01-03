#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        string aux="";
        vector<int> count(11,0);
        aux.reserve(1000000);
        for (int i=1; i<=n; i++){
            aux += to_string(i);
        }
        for (int i=0; i<aux.size(); i++){
            count[aux[i] - '0']++;
        }
        for (int i= 0; i<10; i++){
            cout << count[i];
            if (i == 9) cout << endl;
            else cout << " ";
        }
        
    }   
}