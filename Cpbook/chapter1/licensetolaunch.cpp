#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int bestvalue = -1;
    int bestday = -1;
    cin >> n;
    for (int i=0; i<n; i++){
        int val;
        cin >> val;
        if (bestvalue == -1 or val < bestvalue){
            bestvalue = val;
            bestday = i;
        }
    }
    cout << bestday << endl;
}