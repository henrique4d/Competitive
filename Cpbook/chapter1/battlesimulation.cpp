#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cin >> in;
    bool done[260];
    memset(done, 0, sizeof(done));

    for (int i=0; i<in.size(); i++){
        if (i +2 < in.size()){
            for (int j=0; j<3; j++){
                done[in[i+j]] = true;
            }
        }
        if (done['R'] and done ['B'] and done['L']){
            cout << "C";
            i+=2;
        }
        else if (in[i] == 'R') cout << "S";
        else if (in[i] == 'B') cout << "K"; 
        else if (in[i] == 'L') cout << "H";

        done['R'] = false;
        done['B'] = false;
        done['L'] = false;
    }
    cout << endl;

}