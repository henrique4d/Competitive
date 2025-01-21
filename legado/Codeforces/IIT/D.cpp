#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v(1e6+10, -1);

    v[0] = -2;
    v[1] = 0;

    int cont = 1;

    while (true){
     
        for (int i=1e6+2; i>=1; i--){
            if (cont == 1e6) goto here;
            if (v[i]!= -1){
                if (2*i <= 1e6 and v[2*i] == -1){
                    v[2*i] = i;
                    cont++;
                }
                if (3*i <= 1e6 and v[3*i] == -1){
                    v[3*i] = i;
                    cont++;
                }
                if (i+1 <= 1e6 and v[i+1] == -1){
                    v[i+1] = i;
                    cont++;
                }
            }
        }
        
    }

    here:
    int z;
    cin >> z;
    vector<int> resp;
    for (int l=0; l<z; l++){
        resp.resize(0);
        int d;
        cin >> d;

        while (v[d] != -2){
            resp.push_back(d);
            d = v[d];
        }
        reverse(resp.begin(), resp.end());
        cout << resp.size() << "\n";
        for (int i=0; i< resp.size(); i++){
            if (i!=0) cout << " ";
            cout << resp[i];
        }
        cout << "\n";
    }
}