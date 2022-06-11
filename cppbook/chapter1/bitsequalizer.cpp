#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    for (int k=1; k<=n; k++){
        string a,b;
        cin >> a >> b;
        int contneg =0, contpos=0, contintneg = 0, contintpos = 0;

        for (int i=0; i<a.size(); i++){
            if (a[i] == '0' and b[i] == '1') contneg++;
            else if (a[i] == '1' and b[i] == '0') contpos++;
            else if (a[i] == '?' and b[i] == '1') contintneg++;
            else if (a[i] == '?' and b[i] == '0') contintpos++;
        }


        int posremaining = contpos - contneg;



        int result = 0;
        if (!(contpos - contneg <= contintneg)){
             cout << "Case " << k << ": -1" << endl;
            continue;
        }

        result = max(contpos, contneg) + contintneg + contintpos;
        cout << "Case " << k << ": " <<  result << endl;
    }
}