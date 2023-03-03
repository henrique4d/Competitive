#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> multply(vector<vector<long long int>> &a, vector<vector<long long int>> &b, int n){
    vector<vector<long long int>> result(n, vector<long long int>(n, 0));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                result[i][j]+= a[i][k]*b[k][j];
                result[i][j]%= 1000000007;
                
            }
        }
    }

    return result;
}

long long int teste(long long int n, long long int k, vector<vector<long long int>> &paths){
    //cout << n << endl;
    vector<vector<long long int>> resp(n, vector<long long int>(n,0));
    for (int i=0; i<n; i++){
        resp[i][i] = 1;
    }
    while (k){
        if (k&1){
            resp = multply(resp, paths, n);
        }
        paths = multply(paths,paths,n);
        k/=2;
    }

    long long int final = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            //cout << i << " " << j << endl;
            final += resp[i][j];
            final %= 1000000007;
        }
    }

    return final;
}

int main(){
  
    long long int n,m,k;
    cin >> n >> m >> k;
    //cout << n << " " << m << " " << k << endl;
    vector<vector<long long int>> paths(n, vector<long long int>(n,0));

    int a,b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        a--;
        b--;
        paths[a][b]++;
    }

    long long int resp = teste(n, k, paths);
    cout << resp << endl;


}