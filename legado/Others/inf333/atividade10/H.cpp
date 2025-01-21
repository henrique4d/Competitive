#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        cout << "Case " << l+1 << ": ";
        string in;
        cin >> in;
        vector<int> v(in.size());
        int sum = 0;
        int mult[3];
        memset(mult, 0, sizeof(mult));

        for (int i=0; i<in.size(); i++){
            v[i] = in[i] - '0';
            sum+=v[i];
            mult[v[i]%3]++;
            sum%=3;
        }
        if (sum == 0){  //multiplo de 3 no comeco
            if (mult[0] %2 == 0){
                cout << "T" << endl;
            }
            else{
                cout << "S" << endl;
            }
        }
        else{
            if (mult[sum] == 0){                // nao tem como fazer a primeira jogada
                cout << "T" << endl;
            }
            else if (mult[0] %2 == 0){
                cout << "S" << endl;
            }
            else{
                cout << "T" << endl;
            }
        }       
    }
}