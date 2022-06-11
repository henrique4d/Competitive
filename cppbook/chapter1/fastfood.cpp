#include <bits/stdc++.h>
using namespace std;
int main(){
    int c;
    cin >> c;
    for (int k=0; k<c; k++){
        int n,m;
        cin >> n >> m;
        pair<int,vector<int>> prizes[n];
        for (int i=0; i<n; i++){
            int tickets;
            cin >> tickets;
            for (int j=0; j<tickets; j++){
                int value;
                cin >> value;
                prizes[i].second.push_back(value);
            }
            cin >> prizes[i].first;
        }

        int count[m+1];
        memset(count, 0, sizeof(count));
        for (int i=1; i<=m; i++){
            int val;
            cin >> val;
            count[i] = val;
        }

        int final = 0;
        for (int i=0; i<n; i++){
            int minim = INT_MAX;
            for (int j=0; j<prizes[i].second.size(); j++){
                minim = min(minim, count[prizes[i].second[j]]);
            }
            final += minim*prizes[i].first;
        }
        cout << final << endl;
    }


}