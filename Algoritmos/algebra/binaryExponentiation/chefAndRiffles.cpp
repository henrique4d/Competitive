#include <bits/stdc++.h>
using namespace std;

bool compare(long long int a, long long int b){
    if (a%2 != b%2) return a%2 == 0;
    return a<b;
}
void riffle(vector<long long int> &a, vector<long long int> b, int n){
    
    vector<long long int> newA(n);

    for (int i=0; i<n; i++){
        newA[i] = a[b[i]];
    }
    a = newA;
}


void modPow(long long int n, long long int b){
    vector<long long int> resp;
    vector<long long int> a;

    for (int i=1; i<=n; i++){
        resp.push_back(i);
        a.push_back(i-1);
    }
    sort(a.begin(), a.end(), compare);
    while(b){
        if (b&1){
            riffle(resp, a, n);
        }
        riffle(a,a, n);
        b/=2;
    }

    for (int i=0; i<n; i++){
        cout << resp[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
}


int main(){
    int z;
    cin >> z;
    for (int l=0; l<z; l++){
        long long int n, k;
        cin >> n >> k;
        modPow(n,k);
    }
}
    
