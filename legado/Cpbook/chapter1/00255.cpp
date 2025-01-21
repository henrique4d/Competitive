#include <bits/stdc++.h>
using namespace std;
int main(){

    int a,b,c;
    while (cin >> a >> b >> c){
        char tabuleiro[10][10];
        memset(tabuleiro, '*', sizeof(tabuleiro));
        for (int i=1; i<9; i++){
            for (int j=1; j<9; j++){
                tabuleiro[i][j] = '-';
            }
        }
        if (a == b or a<0 or a>63 or b<0 or b>63){
            cout << "Illegal state\n";
            continue;
        }
        if (c == a or c == b or c<0 or c>63){
            cout << "Illegal move\n";
            continue;
        }


        tabuleiro[(a/8)+1][(a%8)+1] = 'K';
        tabuleiro[(b/8)+1][(b%8)+1] = 'Q';
        
        bool horizontal = false;
        bool vertical = false;

        if (b/8 == c/8) horizontal = true;
        if (b%8 == c%8) vertical = true;

        if (!(vertical == true or horizontal == true)){
            cout << "Illegal move\n" ;
            continue;
        }

        if (horizontal){
            for (int i=min(b%8, c%8); i<= max(b%8, c%8); i++){
                if (i == b%8) continue;
                if (tabuleiro[(b/8)+1][i+1] != '-'){
                    cout << "Illegal move\n";
                    goto here;
                }
                
            }
        }
        if (vertical){
            for (int i=min(b/8, c/8); i<= max(b/8, c/8); i++){
                if (i == b/8) continue;
                if (tabuleiro[i+1][(b%8)+1] != '-'){
                    cout << "Illegal move\n";
                    goto here;
                }
                
            }
        }


        tabuleiro[(c/8)+1][(c%8)+1] = 'Q';
        tabuleiro[(b/8)+1][(b%8)+1] = '-';


        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (abs(i-j)!=1) continue;
                if (tabuleiro[(c/8)+i][(c%8)+j] == 'K'){
                    cout << "Move not allowed\n";
                    goto here;
                }
                if (tabuleiro[(c/8)+i][(c%8)+j] == '-'){
                    tabuleiro[(c/8)+i][(c%8)+j] = 'Q';
                }
            }
        }


        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                if (abs(i-j)!=1) continue;
                if (tabuleiro[(a/8)+i][(a%8)+j] == '-'){
                    cout << "Continue\n";
                    goto here;
                }
            }
        }
        cout << "Stop\n";
        here:
        int asuhsaudfhi;

    }
    

}