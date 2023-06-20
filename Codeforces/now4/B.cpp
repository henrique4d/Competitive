#include <bits/stdc++.h>
using namespace std;
int main(){

    int z;
    cin >> z;
    while (z--){
        int n;
        cin >> n;
        vector<long long int> pos;
        vector<long long int> neg;
        long long int aux = 0;
        for (int i=0; i<n ; i++){
            cin >> aux;
            if ( aux >= 0) pos.push_back(aux);
            else neg.push_back(aux);
        }
        long long int best = 0;
        
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        if (pos.size() == 1 and neg.size() == 1){
            best = pos[0]*neg[0];
        }
        else{
            long long int max_pos = 0;
            long long int max_neg = 0;

            if (pos.size() > 1){
                max_pos = pos[pos.size()-1]*pos[pos.size()-2];
            }
            if (neg.size() > 1){
                max_neg = neg[0]*neg[1];
            }

            best = max(max_pos, max_neg);
        }

        cout << best << endl;
    }
}