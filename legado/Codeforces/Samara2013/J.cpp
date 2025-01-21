#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int maiorAi = -1;
    int maiorBi = -1;

    int a,b;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        if (a > maiorAi){
            maiorAi = a;
            maiorBi = max(maiorBi, b);
        }
    }

    cout << maiorBi << endl;
}