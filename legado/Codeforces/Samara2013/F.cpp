#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int p,q;
    
bool possible(long long int x){
    long long int cont = 0;
    long long int podeDar = x;

    for (long long int i=0; i<v.size(); i++){
        if (p == q){
            if (v[i]-x*q > 0) return false;
        }
        else{
            cont += max((long long int)0,(v[i]-x*q + (p-q-1))/(p-q));
       }
    }
    if (cont > x) return false;
    else return true;
}
int main(){
    long long int n;
    cin >> n;
    v.resize(n);
    cin >> p >> q;
 
    for (long long int &x: v) cin >> x;
    long long int l=0;
    long long int r = 1e9+5;
    long long int meio = l + (r-l)/2;

    while (true){
        if (possible(meio)){
            if (!possible(meio-1)){
                cout << meio << endl;
                return 0;
            }
            r = meio;
        }
        else{
            l = meio;
        }
        meio = l + (r-l)/2;
    }
}