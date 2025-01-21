#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<long long int> v(n);
    for (long long int &x: v) cin >> x;

    vector<pair<long long int, long long int>> ops(k);
    sort(v.begin(), v.end());


    for (int i=0; i<k; i++){
        cin >> ops[i].second;
        cin >> ops[i].first;
    }

    

    

}