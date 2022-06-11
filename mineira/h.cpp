#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,c;
    cin >> l >> c;
    int tabuleiro[l+2][c+2];

    memset(tabuleiro, -1, sizeof(tabuleiro));

    for (int i=1; i<=l; i++){
        for (int j=1; j<=c; j++){
            cin >> tabuleiro[i][j];
        }
    }

    int x,y;
    cin >> x >> y;

    for (int count = 0; count<l+c; count++){
        int countAdjacentes = 0;
        int best = -1;

        for (int i=-1; i<=1; i++){
            for (int j=-1; j<=1; j++){
                if ( !(i == 0 and j == 0) and tabuleiro[x+i][y+j] != -1){
                    countAdjacentes++;
                }
            }
        }

        int div = 0;
        if (countAdjacentes > 0)
            div = tabuleiro[x][y]/countAdjacentes;

        for (int i=-1; i<=1; i++){
            for (int j=-1; j<=1; j++){
                if ( !(i == 0 and j == 0) and tabuleiro[x+i][y+j] != -1){
                    tabuleiro[x+i][y+j]  += div;
                    best = max(best, tabuleiro[x+i][y+j]);
                    
                    tabuleiro[x][y]  -= div;
                }
            }
        }

        if (tabuleiro[x][y-1] == best){
            y = y-1;           
        }
        else if (tabuleiro[x-1][y-1] == best){
            x--;
            y--;
        }
        else if (tabuleiro[x-1][y] == best){
            x--;
        }

        else if (tabuleiro[x-1][y+1] == best){
            x--;
            y++;
        }


        else if (tabuleiro[x][y+1] == best){
            y++;
        }


        else if (tabuleiro[x+1][y+1] == best){
            x++;
            y++;
        }


        else if (tabuleiro[x+1][y] == best){
            x++;
        }


        else if (tabuleiro[x+1][y-1] == best){
            x++;
            y--;
        }
    }










    int result = -1;

    for (int i=1; i<=l; i++){
        for (int j=1; j<=c; j++){
            result = max(result, tabuleiro[i][j]);
        }
    }

    cout << result << endl;


}