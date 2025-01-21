#include <bits/stdc++.h>
using namespace std;
int main(){
    

    while(true){
        bool done[100];
        memset(done,false,sizeof(done));

        vector<int> princess(3);
        vector<int> prince(2);
  
        cin >> princess[0];
        cin >> princess[1];
        cin >> princess[2];

        cin >>prince[0];
        cin >> prince[1];

        done[princess[0]] = true;
        done[princess[1]] = true;
        done[princess[2]] = true;
        done[prince[0]] = true;
        done[prince[1]] = true;
        
        if (princess[0] == 0) return 0;
        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());

        int perdidos = 0;



        auto it = lower_bound(princess.begin(), princess.end(), prince[0]);
        if (it != princess.end()){
            perdidos++;
            princess.erase(it);
        }

        it = lower_bound(princess.begin(), princess.end(), prince[1]);
        if (it != princess.end()){
            perdidos++;
            princess.erase(it);
        }
        if (perdidos == 2){
            cout << -1 << endl;
        }
        else if (perdidos == 1){
            int candidato = princess[1] + 1;
            
            while (done[candidato]) candidato++;

            if (candidato > 52) cout << -1 << endl;
            else cout << candidato << endl;
        }
        else{
            int candidato = 1;
            
            while (done[candidato]) candidato++;

            cout << candidato << endl;
        
        }
    }
    
}