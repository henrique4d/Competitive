#include <bits/stdc++.h>
using namespace std;
 
using ll = long long int;
using vi = vector<int>;
using ii = pair<int,int>;
 
int main(){
    ll n;
 
    cin >> n;
 
    ll inters = 0, aux, resp = 0;
 
    for(int i = 0; i < n; i++){
        cin >> aux;
        inters += aux;
        if(inters < 0)
            if(inters < resp)
                resp = inters;
    }
 
    cout << abs(resp) << endl;   
 
    return 0;
}