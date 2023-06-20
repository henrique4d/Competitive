#include <bits/stdc++.h>
using namespace std;
int main(){

    int z;
    cin >> z;
    while (z--){
        int n, t;
        cin >> n >> t;
        vector<pair<int,int>> v(n);

        for (int i=0; i<n; i++){
            cin >> v[i].first;
            v[i].first += i;
        }

        for (int i=0; i<n; i++){
            cin >> v[i].second;
        }

        int best = -1;
        int index = -1;

        for (int i=0; i<n; i++){
            if (v[i].first <= t and v[i].second > best){
                best = v[i].second;
                index = i;
            }
        }
        if (index != -1) index++;
        cout << index << endl;
    }
}