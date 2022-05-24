#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,r,c;
    while (cin >> l >> r >> c){
        char dungeon[l+2][r+2][c+2];
        int ii, ji,ki;
        queue<int> xq;
        queue<int> yq;
        queue<int> zq;

        for (int i=1; i<=l; i++){
            for (int j=1; j<=r;j++){
                for (int k=1; k<=c;k++){
                    cin >> dungeon[i][j][k];
                    if (dungeon[i][j][k] == 'S'){
                        xq.push(i);
                        yq.push(j);
                        zq.push(k);
                    }
                }
            }
        }


    }
}