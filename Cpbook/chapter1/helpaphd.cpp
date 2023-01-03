#include <bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        string in;
        cin >> in;
        int a,b;
        int index = -1;
        for (int j=0; j<in.size(); j++){
            if (in[j] == '+') index = j;
        }
        if (index == -1 ){
            cout << "skipped" << endl;
            continue;
        }
        a = atoi((in.substr(0, index)).c_str());
        b = atoi((in.substr(index, in.size())).c_str());
        
        cout << a + b << endl;
    }
}