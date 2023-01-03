#include <bits/stdc++.h>
using namespace std;
int main(){
    int nbolas;
    int tempoquique;
    while (cin >> nbolas >> tempoquique){
        if (!nbolas and !tempoquique) return 0;

        bool jafoi[200];
        memset(jafoi,0,sizeof(jafoi));

        bool possivel = true;

        for (int i=0; i<nbolas; i++){
            int value;
            cin >> value;
            //cout << tempoquique%nbolas << endl;
            if (tempoquique%value == 0){
                jafoi[value] = true;
            }else{
                possivel = false;
            }
        }

        bool sobrou = false;
        int resp;
        
        for (int i=2; i<=tempoquique; i++){
            if (tempoquique%i == 0 and !jafoi[i]){
                resp = i;
                sobrou = true;
                break;
            }
        }
        if (sobrou and possivel){
            cout << resp << endl;
        }else{
            cout << "impossivel\n";
        }

    }
    
}