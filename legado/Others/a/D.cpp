#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    int j = 0;
    for (int i=0; i<n; i++){
        if (i%2 ==0){
            j = 0;
            while (j < m){
                cout << j+1 << " " << i+1 << endl;
                j++;
            }
        }
        if (i%2 == 1){
            j = m-1;
            while (j>= 0){
                cout << i+1 << " " << j+1 << endl;
                j--;
            }
        }
    }
}