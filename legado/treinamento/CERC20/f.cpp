#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

const ll MAXN = 2e5+10;
int a[MAXN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> resp(n,50);

    for (int i=0; i<(1<<n); i++){
        for (int j=0; j<n; j++){
            if (i&(1<<j)){
                int soma = 0;
                for (int k=j; k<n; k++){
                    if (i&(1<<k)) soma += a[k];
                }
                if (soma%10 == 0){
                    resp[j] = min(resp[j], __popcount(i));
                }
                break;
            }
        }
    }
    
    for (int i=0; i<n; i++){
        cout << resp[i] << " ";
    }
    cout << endl;
}