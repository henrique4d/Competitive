#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, p;
    cin >> k >> p;
    int values[p];
    int maxvalue = 0;
    for (int i =0; i<p; i++){
        cin >> values[i];
        maxvalue = max(maxvalue, values[i]);
    }

    bool pd[100000 + maxvalue + 1];

    memset(pd,false,sizeof(pd));

    for (int i=0; i<p; i++){
        pd[values[i]] = true;
    }

    for (int i=0; i<100000; i++){
        if (pd[i]){
            for (int j =0; j<p; j++){
                pd[i + values[j]] = true; 
            }
        }
    }

    for (int i=0; i<k; i++){
        int value;
        cin >> value;
        int j = value;
        for (;!pd[j]; j++){ 
        }
        cout << j-value << endl;
    }
}