#include <bits/stdc++.h>
using namespace std;
int main(){
    int cas = 1;
    int n;
    while (cin >> n){
        if (!n) return 0;
        int result = 0;
        int val;
        for (int i=0; i<n; i++){
            cin >> val;
            if (val) result++;
            else result--;
        }
        cout << "Case " << cas << ": " << result << endl; 
        cas++;
    }
}