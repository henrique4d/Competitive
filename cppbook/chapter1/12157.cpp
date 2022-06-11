#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int a = 0; a <t; a++){
        int n;
        cin >> n;
        int mile = 0;
        int juice = 0;
        for (int i=0; i<n; i++){
            int value;
            cin >> value;
            mile += (value/30 + 1)*10;
            juice += (value/60 + 1)*15;
        }
        cout << "Case " << a+1 << ": ";

        if (mile > juice) cout << "Juice " << juice << endl;
        else if (juice > mile) cout << "Mile " << mile << endl;
        else if (juice == mile) cout << "Mile Juice " << mile << endl;
    }
}