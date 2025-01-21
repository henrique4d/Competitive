#include <bits/stdc++.h>
using namespace std;
int main(){
    string in;
    while (getline(cin, in)){
    stringstream ss;

        ss << in;
        vector<long long int> coef;
        long long int aux;
        while (ss >> aux){
            coef.push_back(aux);
        }
        ss.clear();
 
        getline(cin,in);
        ss << in;
        vector<long long int> results;
        while (ss >> aux){
            long long int result = 0;
            for (long long int i=0; i<coef.size()-1; i++){
                result += coef[i];
                result*=aux;
            }
            result += coef.back();
            results.push_back(result);
        }
        for (long long int i=0; i<results.size(); i++){
            cout << results[i];
            if (i == results.size()-1) cout << endl;
            else cout << " ";
        }
        
    }
}