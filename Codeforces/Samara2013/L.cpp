#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin >> n;

    if (n <= 3){
        int final = n/2 + 1;
        cout << final << endl;
        return 0;        
    }

    vector<long long int> divisores;
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            divisores.push_back(i);
            divisores.push_back(n/i);
        }
    }

    sort(divisores.begin(), divisores.end());    
    vector<long long int> dp(divisores.size());
    
    for (int i=0; i<divisores.size(); i++){ 
        dp[i] = divisores[i]/2 + 1;
        for (int j=0;j<i-1; j++){
            if (divisores[i]%divisores[j] == 0){
                dp[i] = min(dp[i],((divisores[i]/divisores[j])/2 + 1)*(dp[j]));
            }
        }
    }
    cout << dp.back() << endl;
    
}