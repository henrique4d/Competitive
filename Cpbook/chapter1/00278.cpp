#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin >> k;
    for (int i=0; i<k; i++){
        char peca;
        int n,m;
        cin >> peca >> n >> m;
        if (peca == 'r'){
            cout << min(n,m) << endl;
        }
        else if (peca == 'k'){
            if (n%2 and m%2){
                
                cout << max(n*m/2+1, m*n/2+1) << endl;
            }
            else
                cout << n*m/2 << endl;
        }
        else if (peca == 'Q'){
            cout << min(n,m) << endl;
        }
        else if (peca =='K'){
            if (n%2) n++;
            if (m%2) m++;
            cout << (n/2)*(m/2) << endl;
        }
    }

    return 0;
}