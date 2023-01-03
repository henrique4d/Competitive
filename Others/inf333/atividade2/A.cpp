#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int z;
    cin >> z;
    vector<int> values(10000);
    for (int l =0; l<z; l++){
        values.resize(0);
        int index, n;
        cin >> index >> n;
        vector<int> medians;
        for (int i=0; i<n; i++){
            int aux;
            cin >> aux;
            values.push_back(aux);
            sort(values.begin(), values.end());
            if (i%2 == 0){
                medians.push_back(values[i/2]);
            }
        }
        
        cout << index << " " << medians.size() << endl;

        for (int i=0; i<medians.size(); i++){
            cout << medians[i];
            if (i>0 && i%10 == 9) cout << endl;
            else if (i == medians.size() - 1) cout << endl;
            else cout << " ";
        }
    }
}