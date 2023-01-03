#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        int final[n];

        memset(final, 0, sizeof(final));
        bool possivel = true;
        for (int i=0; i<n; i++){
            int index, pos;

            cin >> index >> pos;
            //cout << i << " " << pos << " " << i+pos << endl;
            if (i+pos < 0 or i+pos >= n or  final[i+pos] !=0){
                if (possivel)
                    cout << -1 << endl;
                possivel = false;
            }
            else{
                final[i+pos] = index;
            }
        }

        if (possivel){
            for (int i=0; i<n-1; i++){
                cout << final[i] << " ";
            }
            cout << final[n-1] << endl;
        
        }


    }
}