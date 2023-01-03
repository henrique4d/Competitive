#include <bits/stdc++.h>
using namespace std;
int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        if (l > 0) cout << endl;
        int m;
        cin >> m;
        double a,b;
        vector<pair<double, double>> segments;
        while(cin >> a >> b){
            if (!a and !b) break;
            if ((a > m and b > m) or (a<0 and b < 0)) continue;
            segments.push_back(make_pair(a,b));
        }

        sort(segments.begin(), segments.end());
        double start_atual = 0;
        
        int cont = 0;
        int i = 0;
        vector<int> best_index;
        while (true){
            int index = 0;
            double best = INT_MIN;

            while (i < segments.size() and segments[i].first <= start_atual){
                if (segments[i].second > best){
                    best = segments[i].second;
                    index = i;
                }
                i++;
            }
            best_index.push_back(index);
            start_atual = best;
            cont++;
            if (best >= m){
                cout << cont << endl;
                for (int j=0; j<cont; j++){
                    cout << segments[best_index[j]].first << " " << segments[best_index[j]].second << endl;
                }
                break;
            }
            if (i == segments.size() or best == INT_MIN){
                cout << 0 << endl;
                break;
            }
        }
    }
}