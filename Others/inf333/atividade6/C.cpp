#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,m;
    vector<long long int> heads;
    vector<long long int> knights;
    while (cin >> n >> m){
        if (!n and !m) return 0;
        heads.resize(n);
        knights.resize(m);
        for (int i=0; i<n; i++){
            cin >> heads[i];
        }
        for (int i=0; i<m; i++){
            cin >> knights[i];
        }
        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());
        int i=0;
        int j=0;
        long long int result = 0;
        while (true){
            if (j == n){
                cout << result << endl;
                break;
            }
            if (i == m){
                cout << "Loowater is doomed!" << endl;
                break;
            }
            if (knights[i] >= heads[j]){
                result+=knights[i];
                j++;
            }
            i++;
        } 
    }
}