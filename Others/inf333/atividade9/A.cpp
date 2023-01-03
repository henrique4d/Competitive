#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    int cont = 1;
    bool escreveu = false;
    while (cin >> n >> k){
        if (!n and !k) return 0;
        
        vector<vector<int>>d(n, vector<int>(n, INT_MIN));
        for (int i=0; i<n; i++){
            d[i][i] = 0;
        }
        for (int j=0; j<k; j++){
            int a,b,val;
            cin >> a >> b >> val;
            a--;
            b--;
            val--;
            d[a][b] = val;
            d[b][a] = val;
        }
        for (int k=0; k<n; k++){
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    //cout << i << " " << j << " " << d[i][j] << " ";
                    d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
                    //cout << d[i][j] << endl;
                }
            }
        }
        int start, end, passageiros;
        cin >> start >> end >> passageiros;
        start--;
        end--;
        //cout << start << " " << end << " " << passageiros << endl;
        //cout << "////////////////\n" << endl;
        //cout << d[start][end] <<endl;
        int resp = (passageiros + d[start][end]-1)/d[start][end];
        printf("Scenario #%d\n", cont);
        cont++;
        printf("Minimum Number of Trips = %d\n", resp);
        printf("\n");       
    }
}