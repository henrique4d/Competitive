#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m;
    while (cin >> n >> m){
        if (!n and !m) return 0;
        
        vector<vector<bool>> presenca(m, vector<bool>(n));
    

        //bool tudo = rue;
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                bool aux;
                cin >> aux;

                presenca[i][j] = aux;
            }
        }

        for (int i=0; i<n; i++){
            bool tudo = true;
            for (int j=0; j<m; j++){
                if (!presenca[j][i]){
                    tudo = false;
                }
            }
            if (tudo){
                cout << "yes" << endl;
                goto here;
            }
        }
        cout << "no\n";

        here:
        int asuhdfhuasdhf;
    }
    return 0;
}