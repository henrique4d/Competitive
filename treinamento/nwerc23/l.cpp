#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 200;
bool used[MAXN][MAXN];

int main(){
    ll n,quantNavios;
    ll cont = 0;
    cin >> n >> quantNavios;
    string resp;
    ll total = quantNavios*5;

    for (int i=0; i < (n+4)/5; i++){
        for (int j=0; j < (n+4)/5; j++){
            bool navio = false;
            for (int k =1; k<=5; k++){
                if (i*5 +k > n or j*5 + k > n)continue;
                cout << i*5+k << " " << j*5+k << endl;
                cin >> resp;
                if (resp == "hit" or resp == "sunk"){
                    cont++;
                    if (cont == total ) return 0;
                    for (int d = 1; d<=4; d++){
                        if (i*5 + k + d <= n){
                            cout << i*5 + k + d << " " << j*5+k << endl;
                            cin >> resp;
                            if (resp == "hit" or resp == "sunk"){
                                cont++;
                            }
                            if (cont == total ) return 0;
                        }
                    }

                    for (int d = 1; d<=4; d++){
                        if (j*5 + k + d <= n){
                            cout << i*5 + k<< " " << j*5+k+d << endl;
                            cin >> resp;
                            if (resp == "hit" or resp == "sunk"){
                                cont++;
                            }
                            if (cont == total ) return 0;
                        }
                    }

                    for (int d = 1; d<=4; d++){
                        if (i*5 + k - d >= 1){
                            cout << i*5 + k - d << " " << j*5+k << endl;
                            cin >> resp;
                            if (resp == "hit" or resp == "sunk"){
                                cont++;
                            }
                            if (cont == total ) return 0;
                        }
                    }

                    for (int d = 1; d<=4; d++){
                        if (j*5 + k - d >= 1){
                            cout << i*5 + k<< " " << j*5+k-d << endl;
                            cin >> resp;
                            if (resp == "hit" or resp == "sunk"){
                                cont++;
                            }
                            if (cont == total ) return 0;
                        }
                    }
                }

                if (cont == total) return 0;
            }

        }
    }
}