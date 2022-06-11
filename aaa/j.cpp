#include <bits/stdc++.h>
using namespace std;
int ganhadores[2][20000];
int pot3[9];
int board[9];

bool win(int player, int i, int j, int k){
    return board[i] == player and board[j] == player and board[k] == player;
}

void countWins(int key, int player){
    if (ganhadores[0][key] == -1){
        int opp = 3-player;
        if (win (opp, 0,1,2) or win(opp, 3,4,5) or win(opp, 6,7,8) or win(opp, 0,3,6) or win(opp, 1,4,7) or win(opp, 2,5,8) or win(opp, 0,4,8)  or win(opp, 2,4,6)){
            ganhadores[opp-1][key] = 1;
            ganhadores[player-1][key] = 0;
        }
        else{
            ganhadores[0][key] = 0;
            ganhadores[1][key] = 0;

            for (int i=0; i<9; i++){
                if (board[i] == 0){
                    board[i] = player;
                    int newKey = key + player*pot3[i];
                    countWins(newKey, opp);
                    ganhadores[0][key] += ganhadores[0][newKey];
                    ganhadores[1][key] += ganhadores[1][newKey];
                    board[i] = 0;
                }
            }
        }
    }
}

int main(){
    memset(ganhadores, -1, sizeof(ganhadores));
    pot3[0] = 1;
    for (int i=1; i<9; i++){
        pot3[i] = pot3[i-1]*3;
    }

    memset(board, 0, sizeof(board));

    countWins(0,1);
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string input;
        cin >> input;

        int key = 0;
        for (int j=0; j<input.size(); j++){
            if (input[j] == '.') key += pot3[j]*0;
            else if (input[j] == 'X') key += pot3[j]*1;
            else key+= pot3[j]*2;
        }

        cout << ganhadores[0][key] << " " << ganhadores[1][key] << endl;

    }
}