#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m,'.'));
    ll x,y;
    ll k;
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> x >> y;
        a[x][y] = 'X';
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    ll maiorSoma = 0;
    vector<ll> ans;
    ll soma_atual = 0;
    for (int i=0; i<n; i++){
        soma_atual = 0;
        for (int j=0; j<m; j++){
            soma_atual += a[i][j] == 'X';
        }
        if (soma_atual > maiorSoma){
            maiorSoma = soma_atual;
            ans.clear();
        }
        if (soma_atual == maiorSoma) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << "Linhas: ";
    for (auto x:ans) cout << x << " ";
    cout << endl;

    maiorSoma = 0;
    ans.clear();
    for (int i=0; i<m; i++){
        soma_atual = 0;
        for (int j=0; j<n; j++){
            soma_atual += a[j][i] == 'X';
        }
        if (soma_atual > maiorSoma){
            maiorSoma = soma_atual;
            ans.clear();
        }
        if (soma_atual == maiorSoma) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << "Colunas: ";
    for (auto x:ans) cout << x << " ";
    cout << endl;
    //


}