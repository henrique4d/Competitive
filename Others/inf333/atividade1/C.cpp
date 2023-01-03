#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        vector<double> values(n);
        double media = 0;
        for (int i=0; i<n; i++){
            cin >> values[i];
            media += values[i];
        }
        sort(values.begin(), values.end());
        media/=n;
        //cout << "media: " << media << endl;
        double finalup = 0;
        double mediaup = ceil(media * 100.0) / 100.0; 
        //cout << "media up: " << mediaup << endl;
        for (auto it = lower_bound(values.begin(), values.end(), media); it!= values.end(); it++){
            //double aux = (*it) - mediaup;
            //double gambiarra = ceil(aux * 100.0) / 100.0;
            //cout << *it << " " << media << " " << aux << " " << gambiarra << " " << 2*aux-gambiarra <<  endl;
            finalup += *it - mediaup;
        }


        double finallower = 0;
        double medialower = floor(media * 100.0) / 100.0; 
        for (auto it =values.begin(); it!= lower_bound(values.begin(), values.end(), media); it++){
            //double aux = (*it) - mediaup;
            //double gambiarra = ceil(aux * 100.0) / 100.0;
            //cout << *it << " " << media << " " << aux << " " << gambiarra << " " << 2*aux-gambiarra <<  endl;
            //cout << media << " " << *it << endl;

            finallower += medialower - *it;
        }
        //cout << "media lower: " << medialower << endl;

        //cout << finalup << " " << finallower << endl;


        cout << fixed << setprecision(2) << "$" << max(finalup, finallower) << endl;
    }
}