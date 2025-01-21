#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using vi = vector<int>;
using ii = pair<int,int>;
 
int main(){
    ll n;
    cin >> n;
    ll aux1, aux2;
    ll resp = 0;
 
    cin >> aux1 >> aux2;
    n--;
    resp = aux2 + aux1;
 
    while(n--){
    cin >> aux1 >> aux2;
    if(aux1 <= resp)
        resp+= aux2;
    else if(aux1 > resp){
        resp = aux1 + aux2;
        }
    }
 
    cout << resp << endl;
 
    return 0;
}