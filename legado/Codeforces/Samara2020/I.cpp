#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> v(n);
    long long int ncores = 0;

    for (int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
        ncores = max(ncores, v[i].second);
    }

    vector<long long int> cores[ncores + 1];

    for (int i=0; i<n; i++){
        cores[v[i].second].push_back(v[i].first);
    }

    for (int i=0; i<=ncores;i++){
        int tam = cores[i].size();
        for (int j=0; j<tam-1; j++){
            if (cores[i][j+1] < cores[i][j]){
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;

}