#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        string in;
        cin >> in;
        //cout << in << endl;

        for (int i=1; i<=in.size(); i++){
            for (int j=1; i+j+1 <= in.size(); j++){
                int k = in.size()-i-j;
                //cout << i << " " << j << " " << k << endl;
                string A = in.substr(0,i);
                string B = in.substr(i,j);
                string C = in.substr(i+j,k);
                
                //if (k ==0 ) continue;
                if ( (A <= B and C <=B) or (B<=A and B<=C)){
                    cout << A << " " << B << " " << C << endl;
                    goto here;
                }
            }
        }

        cout << ":(\n";
        here:
        int a;
    }
}