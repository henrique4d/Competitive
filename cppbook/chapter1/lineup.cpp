#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string jogadores[n];
    for (int i=0; i<n; i++){
        cin >> jogadores[i];
    }

    bool inc = true;
    bool dec = true;
    for (int i=0; i<n-1; i++){
        if (jogadores[i+1] > jogadores[i]) dec = false;
        if (jogadores[i+1] <jogadores[i]) inc = false;
    }
    if (dec) cout << "DECREASING" << endl;
    else if (inc) cout << "INCREASING" << endl;
    else cout << "NEITHER" << endl;
}