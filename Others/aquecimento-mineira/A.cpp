#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string in;
    for (int i=0; i<n ; i++){
        int cont1=0;
        int cont2=0;
        cin >> in;
        if (in.size() == 5) cout << 3 << endl;
        else{
            for (int i=0; i<3; i++){
                if (in[i] == "one"[i]) cont1++;
                if (in[i] == "two"[i]) cont2++;
            }
            if (cont1 > cont2) cout << 1 << endl;
            else cout << 2 << endl;
        }
        
    }
}