#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v (1e6+5, 1);

    for (int i=1; i<=1e6; i++){
        for (int j=2; j<=sqrt(i); j++){
            if (i%j == 0){
                v[i]+=i/j;
                if (i/j != j)
                    v[i]+=j;
            }
        }
    }
    v[1] = 0;

    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int pos;
        cin >> pos;
        //cout << pos << " " << v[pos] << endl;
        if (v[pos] < pos){
            cout << "deficient\n";
        }
        else if (v[pos] == pos){
            cout << "perfect\n";
        }
        else{
            cout << "abundant\n";
        }
    }
}