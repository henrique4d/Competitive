#include <bits/stdc++.h>
using namespace std;

long long int fat(long long int n){
    if (n == 0) return 1;
    return n*fat(n-1);
}
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int count[15];
        memset(count, 0,sizeof(count));
        int contreps = 0;
        for (int j=0; j<6; j++){
            int val;
            cin >> val;
            if (count[val]) contreps++;
            count[val]++;
        }
        long long int result;
        result = fat(6-contreps)/fat(6-contreps - 4);
        cout << result << endl;
    }
}