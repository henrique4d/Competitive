#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> dp(pow(10,8));

    dp[0] = make_pair(1,1);

    dp[1] = make_pair(1,2);
    bool direita = false;
    int cont = 2;

    while (true){
        dp[cont] = dp[cont-1];
        if (direita){
            dp[cont].first--;
            dp[cont].second++;
        }
        else{
            dp[cont].first++;
            dp[cont].second--;
        }
        if (dp[cont].first == 1 and direita){
            cont++;
            dp[cont] = dp[cont-1];
            dp[cont].second++;
            direita = false;
        }
        else if (dp[cont].second == 1 and !direita){
            cont++;
            dp[cont] = dp[cont-1];
            dp[cont].first++;
            direita = true;
        }

        cont++;
        if (cont == 10000250) break;
    }
    
    int in;
    while (cin >> in){
        cout << "TERM " << in << " IS " << dp[in-1].first << "/" << dp[in-1].second << endl;
    }
}