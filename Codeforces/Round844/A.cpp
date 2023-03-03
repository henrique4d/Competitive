#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
       
        int x,y,z;
        int x1,x2;
        int y1,y2;

        cin >> x >> y >> z >> x1 >> y1 >> x2 >> y2;
        int resp = INT_MAX;

        int poss1 = z + y2 + y1 + abs(x1-x2);
        resp = min(resp, poss1);
        int poss2 = z + x2 + x1 + abs(y2-y1);
        resp = min(resp, poss2);
        
        int poss3 = z + (y-y2) + (y-y1) + abs(x1-x2);
        resp = min(resp, poss3);
        
        int poss4 = z + (x-x2) + (x-x1) + abs(y2-y1);
        resp = min(resp, poss4);

        cout << resp << endl;

     

    }
}
