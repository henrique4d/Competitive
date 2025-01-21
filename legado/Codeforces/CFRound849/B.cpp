#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        int n;
        cin >> n;
        string path;
        cin >> path;
        int x = 0;
        int y = 0;
        for (int i=0; i<n; i++){
            if (path[i] == 'L')x--;
            if (path[i] == 'R')x++;
            if (path[i] == 'U')y++;
            if (path[i] == 'D')y--;
            
            if (x == 1 and y == 1){
                cout << "YES\n";
                goto here;
            }
        }
        cout << "NO\n";
        here:
        int asuhhua;
        
    }
}