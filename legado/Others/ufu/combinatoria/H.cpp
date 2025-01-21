#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;
    while(cin >> a){
        cin >> b;
        if (a == "acabou" and b== "acabou") return 0;
        int counta[260];
        memset(counta, 0, sizeof(counta));
        for (int i=0; i<a.size(); i++){
            counta[a[i]]++;
        }

        int countb[260];
        memset(countb,0,sizeof(countb));
        for (int i=0; i<b.size(); i++){
            countb[b[i]]++;
        }

        string final;
        for (int i = 'a'; i<= 'z'; i++){
            for (int j=0; j<min(counta[i], countb[i]); j++){
                final.push_back(i);
            }
        }

        cout << final << endl;
    }
}