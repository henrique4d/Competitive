#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int hash = 0;
    scanf("%d",&n);
   
    long long int aux;
    for (int i=0; i<n; i++){
        scanf("%lli",&aux);
        if ((n&1) != (i&1)) hash += aux;
        else hash -= aux;
    }

    int k;
    cin >> k;
    long long int a,b, c;
    long long int newHash;
    for (int i=0; i<k; i++){
        scanf("%lli %lli %lli",&a, &b, &c);
        
        a--;
        b--;
        if ((a&1) != (b&1)){
            printf("%lli\n", hash);
            continue;
        }
        if ( (a&1) != (n&1) and (b&1) != (n&1)) hash+=c;
        else hash -= c;
        printf("%lli\n", hash);
            
    }
    return 0;
}