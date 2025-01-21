#include <bits/stdc++.h>
using namespace std;
int main(){
    int count[256];
    memset(count, 0, sizeof(count));
    string card;
    for (int i=0; i<5; i++){
        cin >> card;
        count[card[0]]++;
    }
    int maxim = 0;
    for (int i=0; i<256; i++){
        maxim = max(maxim,count[i]);
    }

    cout << maxim << endl;
}