#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

const ll MAXN = 2e5+10;
int a[MAXN];
int resp[MAXN];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n; i++){
        resp[i] = -1;
        int soma = 0;
        
        for (int j=0; i+j<n; j++){
            soma += a[i+j];
            if (soma%10 == 0){
                resp[i] = j+1;
                break;
            }
        }
    }

    
    for (int i=0; i<n; i++){
        cout << resp[i] << " ";
    }
    cout << endl;
}