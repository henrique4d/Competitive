    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int n,m,k;
        cin >> n >> m >> k;
        int cor[n][m];
        k++;

        if (k > n*m){
            cout << -1 << endl;
            return 0;
        }
        int count[4];
        memset(count, 0, sizeof(count));
        int mais_aparece = 0;
        if (k == n*m){
            for (int i=0; i<n; i++){
                for (int j=0; j<m; j++){
                    cin >> cor[i][j];
                    count[cor[i][j]]++;
                    mais_aparece = max(mais_aparece, count[cor[i][j]]);
                }
            }
            int numMovs = n*m-mais_aparece;
            cout << numMovs << endl;
            return 0;
        }
        if ( n >1 and m >1){
            cout << -1 << endl;
            return 0;
        }

        if ( (max(n,m) -1)/2 >= k ){
            cout << -1 << endl;
            return 0;
        }
        
    
        
        int linha[max(n,m)];

        for (int i=0; i<max(n,m); i++){
            cin >> linha[i];
        }

        int best = INT_MAX;

        for (int coratual = 1; coratual <=3; coratual++){
            int cordiferente = 0;

            bool temcordiferente = false;
            for (int i=max(n,m) - k; i<k; i++){
                if (linha[i] != coratual) temcordiferente = true;
            }
            if (!temcordiferente) cordiferente+=2;
            for (int i=0; i<max(n,m); i++){
                if (linha[i] != coratual) cordiferente++;
            }
            best = min(best, cordiferente);

        }

        cout << best << endl;
        return 0;
    }   