#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    for (int a =0; a<k; a++){
        int n;
        cin >> n;
        int votes = 0;
        int winnerVotes = -1;
        int winner = -1;
        bool tie = false;
        for (int i=1; i<=n; i++){
            int value;
            cin >> value;
            votes += value;
            if (value > winnerVotes){
                winnerVotes = value;
                winner = i;
                tie = false;
            }
            else if (value == winnerVotes){
                tie = true;
            }
        }
        if (tie){
            cout << "no winner\n";
        }
        else{
            if (winnerVotes > votes/2) cout << "majority winner ";
            else cout << "minority winner ";
            cout << winner << endl;
        }
}
}