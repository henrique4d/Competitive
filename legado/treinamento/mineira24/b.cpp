#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1600;

bool m[MAXN][MAXN][4];

int n;
char c;
int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> c;
            m[i][j][0] = c - '0';
        }
    }

    for (int k=1; k<4; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                m[i][j][k] = m[j][n-1-i][k-1];
            }
        }
    }

    ll resp = 0;
    bool eq0 = true;
    bool eq1 = true;
    bool eq2 = true;
    bool eq3 = true;
    for (int k=0; k<n/2; k++ ){
        for (int i=0; i<=k; i++){
            if (!(m[k][i][0] == m[k][i][1] and m[k][i][0] == m[k][i][2] )) eq3 = false;
            if (!(m[i][k][0] == m[i][k][1] and m[i][k][0] == m[i][k][2] )) eq3 = false;

            if (!(m[k][i][0] == m[k][i][2] and m[k][i][0] == m[k][i][3] )) eq1 = false;
            if (!(m[i][k][0] == m[i][k][2] and m[i][k][0] == m[i][k][3] )) eq1 = false;

            if (!(m[k][i][0] == m[k][i][1] and m[k][i][0] == m[k][i][3] )) eq2 = false;
            if (!(m[i][k][0] == m[i][k][1] and m[i][k][0] == m[i][k][3] )) eq2 = false;

            if (!(m[k][i][1] == m[k][i][2] and m[k][i][1] == m[k][i][3] )) eq0 = false;
            if (!(m[i][k][1] == m[i][k][2] and m[i][k][1] == m[i][k][3] )) eq0 = false;
        }
        if (eq0 or eq1 or eq2 or eq3) resp = k+1;
    }
    cout << resp << endl;
}