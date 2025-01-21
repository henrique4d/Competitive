#include <bits/stdc++.h>
using namespace std;
int mod(int a, int b){
    if (a < 0) return a + b;
    return a%b;
}
int min(int a, int b, int c){
    return min(min(a,b),c);
}

int main(){
    int n,m;
    while (cin >> n >> m){
        int v[n][m];
        int dp[n][m];
        pair<bool,set<int>> path[n][m];
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                path[i][j].first = false;
            }
        }
        //memset(path, false, sizeof(path));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        for (int i=0; i<n; i++){
            dp[i][0] = v[i][0];
        }
        for (int j=1; j<m; j++){
            for (int i=0; i<n; i++){
                dp[i][j] = v[i][j] + min( dp[mod(i-1,n)][j-1],dp[mod(i,n)][j-1], dp[mod(i+1,n)][j-1]);
            }
        }
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "******************" << endl;
        
        queue<pair<int,int>> posicoes;

        int menor = INT_MAX;
        int pos = 0;
        for (int i=0; i<n; i++){
            if (dp[i][m-1] < menor){
                pos = i;
                menor = dp[i][m-1];
            }
        }
        
        for (int i=0; i<n; i++){
            if (dp[i][m-1] == menor){
                posicoes.push(make_pair(i,-1));
            }
        }

        int final_value = menor;
        //cout << pos << endl;



        for (int j=m-2; j>=0; j--){
            bool done[110];
            memset(done, false, sizeof(done));
            int tam = posicoes.size();
            //cout << tam << endl;
            for (int c=0; c<tam; c++){
                pos = posicoes.front().first;
                int veio_de = posicoes.front().second;
                posicoes.pop();
                path[pos][j+1].first = true;
                //path[pos][j+1].second.insert(veio_de);
                

                if (done[pos]) continue;
                done[pos] = true;
                
                menor = INT_MAX;
                //cout << "posicao antes: " << pos << endl;
                int pos_orig = pos;
                for (int i=-1; i<=1; i++){

                    //cout << dp[mod(pos_orig+i,n)][j] << " " << menor << " " << mod(pos_orig+i,n) << " " << pos_orig << " " << i  << endl;
                    if ( dp[mod(pos_orig+i,n)][j] < menor or (dp[mod(pos_orig+i,n)][j] == menor and mod(pos_orig+i,n) < pos)  ){
                        pos = mod(pos_orig+i,n);
                        menor = dp[mod(pos_orig+i,n)][j];
                    }
                }
                for (int i=-1; i<=1; i++){
                    if (dp[mod(pos_orig+i,n)][j] == menor){
                        path[pos_orig][j+1].second.insert(mod(pos_orig+i,n));
                        //cout << "adicionando que ele pode chegar na posicao: " << mod(pos_orig+i,n) << " vindo de " << pos_orig << endl;
                        posicoes.push(make_pair(mod(pos_orig+i,n), pos_orig));        
                    }
                }

                //cout << "posicao depos: " << pos << endl;
                //posicoes.push(pos);
                //cout << pos << endl;
            }
        }

        while (!posicoes.empty()){
            path[posicoes.front().first][0].first = true;
            posicoes.pop();
        }
        // cout << "///////" << endl;
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         cout << path[i][j].first << "(";
        //         for (auto it = path[i][j].second.begin(); it!= path[i][j].second.end(); it++){
        //             cout << *it << "-";
        //         }
        //         cout << ")  ";
        //     }
        //     cout << endl;
        // }
        // cout << "//////" << endl;
       

        int next = 0;
        int pos_atual = 0;
        for (; pos_atual<n; pos_atual++){
            if (path[pos_atual][0].first) break;
        }
        queue<int> resp;
        //cout << pos_atual << " ";
        resp.push(pos_atual);
        next = INT_MAX;
        //cout << pos_atual << endl;
        for (int j=1;j<m; j++){
            for (int i=-1; i<=1; i++){
                //cout << path[mod(pos_atual+i,n)][j] << " " << mod(pos_atual+i,n) << endl;
                if ( path[mod(pos_atual+i,n)][j].first and path[mod(pos_atual+i,n)][j].second.find(pos_atual) != path[mod(pos_atual+i,n)][j].second.end()     and mod(pos_atual+i,n) < next){
                    //cout << "entrou aqui" << endl;
                    next = mod(pos_atual+i,n);
                }
            }
            //cout << next << endl;
            pos_atual = next;
            next = INT_MAX;
            resp.push(pos_atual);
        }
   
        for (int i=0; i<m; i++){
            cout << resp.front()+1;
            resp.pop();
            if (i < m-1) cout << " ";
            else cout << endl;
        }

        cout << final_value << endl;
        //cout << "//////////////////\n";

        
    }

}