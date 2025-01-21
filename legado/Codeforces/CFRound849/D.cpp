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
        vector<int> cont(255,0);
        vector<int> cont2(255,0);
        
        for (int i=0; i<n; i++){
            cont[path[i]]++;
        }

        int best = 0; 
        for (int i=0; i<n; i++){
            int val = 0;
            cont2[path[i]]++;
            

            for (int j='a'; j<='z'; j++){
                if (cont2[j]) val++;
                if (cont[j] - cont2[j] >0) val++;
                
            }
            best = max(best, val);
        }

        cout << best << endl;


    }
}