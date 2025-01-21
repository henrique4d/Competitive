#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<long long int> v(15);
    bool first = true;
    while (cin >> n){
        if (!n) return 0;
        if (first) first = false;
        else cout << endl;

        for (int i=0; i<n; i++){
            cin >> v[i];
        }

        for (int i=(1<<n) -1; i>=0; i--){
            if ( __builtin_popcount(i) == 6 ){   
                auto num = bitset<13>(i);
                //cout << num << endl;
                int cont = 0;

                for (int i=0; i<n; i++){
                    if (num[n - 1 - i]){

                        cout << v[i];
                        if (cont == 5) cout << endl;
                        else{
                            cout << " ";
                        }
                        cont++;
                    }
                }
            }
        }
    }
}