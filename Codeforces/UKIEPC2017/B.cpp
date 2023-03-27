#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].first;
        cin >> p[i].second;
    }

    long double maxDist = 0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            maxDist = max(maxDist,(long double) sqrt( pow(p[i].first - p[j].first,2) + pow(p[i].second - p[j].second, 2)));
            cout << maxDist << endl;
        }
    }

    cout << maxDist << endl;
}