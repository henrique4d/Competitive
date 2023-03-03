#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;

        if (n == 2){
            cout << "1 3\n4 2\n";
            continue;
        }
        vector<vector<int>> m(n, vector<int>(n,0));

        int val1 = 1;
        int val2 = n*n;
        
        vector<bool> used(n*n+1, false);



        for (int i=0; i<n; i++){
            m[i][i] = i+1;
        }

        int val = n*n;
        for (int k=0; k<n-1; k++)
        {
            for (int i=1; i+k<n; i++){
                m[i+k][i-1] = val;
                //cout << "colocando o valpar na posicao " << i << " " << i << endl;
                val--;
            }
            for (int i=1; i+k<n; i++){
                m[i-1][i+k] = val;
                val--;
            }
     
        }


        // for (int i=1; i<n; i++){
        //     for (int k=0; i+k<n; k++){
        //         m[i+k][i+k] = valpar;
        //         used[valpar] = true;
        //         valpar-=2;
                
        //     }
        // }
        // for (int i=1; i<n; i++){
        //     for (int j=0; j < i; j++){
        //          m[i][i-j] = valpar;
        //         used[valpar] = true;
        //         valpar-=2;
                
        //     }
        // }


        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (j!= 0) cout << " ";
                cout << m[i][j];
            }
            cout << endl;
        }
    }
}