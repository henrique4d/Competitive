#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        cin.ignore();
        string name;
        getline(cin,name);
        bool soup = false, pancakes = false;
        for (int j = 0; j<k; j++){
            string prato;
            getline(cin,prato);
            if (prato == "pea soup") soup = true;
            if (prato == "pancakes") pancakes = true;
        }

        if (soup and pancakes){
            cout << name << endl;
            return 0;
        
        }
    }

    cout << "Anywhere is fine I guess\n";


}