#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int k=0; k<t; k++){
        string in;
        cin >> in;
        int result = 0;
        int count = 0;
        for (int i=0; i<in.size(); i++){
            if (in[i] == 'O'){
                result += ++count;
            }else count = 0;
        }
        cout << result << endl;
    }
}