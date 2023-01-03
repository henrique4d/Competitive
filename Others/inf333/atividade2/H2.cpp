#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        vector<pair<double,int>> ratio_position(n);

        for (int i=0; i<n; i++){
            int tempo, preco;
            cin >> tempo >> preco;
            ratio_position[i] = make_pair((double)tempo/preco, i);
        }

        sort(ratio_position.begin(), ratio_position.end());
        if (l) cout << endl;
        for (int i=0; i<n; i++){
            cout << ratio_position[i].second+1;
            if (i == n-1) cout << endl;
            else cout << " ";
        }
    }
}