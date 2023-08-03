#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    char in[n][m];
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> in[i][j];
        }
    }
    char resp[9][9];
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            resp[i][j] = '?';
        }
    }
    for (int i=0; i<=2; i++){
        for (int j=0; j<=2; j++){
            resp[i][j] = '#';
        }
    }
    for (int i=6; i<=8; i++){
        for (int j=6; j<=8; j++){
            resp[i][j] = '#';
        }
    }
    for (int i=0; i<4; i++){
        resp[i][3] = '.';
        resp[3][i] = '.';
        
        resp[5][8-i] = '.';
        resp[8-i][5] = '.';
    }
    // for (int i=0; i<9; i++){
    //     for (int j=0; j<9; j++){
    //         cout << resp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<pair<int,int>> final;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int i2 = i;
            int j2 = j;
            if (i2 + 9 <= n and j2 + 9 <= m){
                for (i2=0; i2<9; i2++){
                    for (j2=0; j2<9; j2++){
                        
                        if ((in[i+i2][j+j2] == '.' and resp[i2][j2] == '#') or (in[i+i2][j+j2] == '#' and resp[i2][j2] == '.')){
                            goto here;
                        }
                    }
                }
                final.push_back({i,j});
                here:
                int asuhdf;
            }
        }
    }
    sort(final.begin(), final.end());
    for (auto it : final){
        cout << it.first + 1 << " " << it.second + 1<< endl;
    }
}