#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int val;
    set<long long int> s;
    vector<long long int> v;
    while (cin >> n){
        if (!n) return 0;
        long long int best = INT_MIN;
        s.clear();
        v.resize(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }
        for (int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
                s.insert( abs(v[i] - v[j]));
            }
        }
        for (int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
                if (s.find(v[i] + v[j]) != s.end()){
                    best = max(best, v[i] + v[j]);
                }
            }
        }
        if (best == INT_MIN){
            cout << "no solution\n";
        }
        else{
            cout << best << endl;
        }
    }
}
