#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while (cin >> n >> m){
        if (!n and !m) return 0;

        int ataque[n];
        int defesa[m];
        for (int i=0; i<n; i++){
            cin >> ataque[i];
        }
        for (int j=0; j<m; j++){
            cin >> defesa[j];
        }

        sort(ataque, ataque+n);
        sort(defesa, defesa+m);

        if (ataque[0] < defesa[1]) cout << "Y\n";
        else cout << "N\n";
    }
}