#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin >> n){
        if (!n) return 0;
        long long int result =0;
        for (int i=1; i<=n; i++){
            result += pow(i,2);
        }
        cout << result << endl;
    }
}