#include<bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n,m;
        cin >> n >> m;
        int matriz[n][m];
        bool tem_aresta[n][n];
        memset(tem_aresta, false, sizeof(tem_aresta));

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> matriz[i][j];
            }
        }

        bool incident = true;
        for (int j=0; j<m; j++){
            int a = -1;
            int b = -1;

            int cont = 0;
            for (int i=0; i<n; i++){
                cont+= matriz[i][j];
                if (matriz[i][j] and a == -1) a = i;
                else if (matriz[i][j] and b == -1) b = i;
            }
            if (cont != 2 and cont !=0) incident = false;
            if (tem_aresta[a][b] == true) incident = false;
            tem_aresta[a][b] = true;

        }

        if (incident) cout << "Yes\n";
        else cout <<"No\n";
    }
}