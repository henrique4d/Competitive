#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    pair<long long int,int> aux[n];

    for (int i=0; i<n; i++){
        long long int val;
        cin >> val;
        aux[i]=make_pair(val, i);
    }

    sort(aux, aux + n);

    bool done[n];
    memset(done, false, sizeof(done));
    vector<vector<int>> results;
    for (int i=0; i<n; i++){
        int atual = i;
        vector<int> sub;
        while (!done[atual]){
            done[atual] = true;
            sub.push_back (aux[atual].second);
            atual = aux[atual].second;
        }
        if (!sub.empty()){
            results.push_back(sub);
        }
    }
    cout << results.size() << '\n';
    for (int i=0; i<results.size(); i++){
        cout << results[i].size() << " ";
        for (int j=0; j<results[i].size(); j++){
            cout <<results[i][j]+1 << " ";
        }
        cout << '\n';
    }
}