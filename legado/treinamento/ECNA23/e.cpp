#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

string s;
ll resp = 1e17;

void dfs(int pos, ll val){
    // cout << pos << " " <<  val << endl;
    if (val < 0) return;
    if (pos == -1){
        resp = min(resp, val);
        return;
        // cout << val << endl;
    }
    if (s[pos] == 'O'){
        if ((val-1)%3 == 0 and ((val-1)/3)%2 == 1){
            if ((val-1)/3 <= 1) return;
            dfs(pos-1, (val-1)/3);
        }
    }
    else if (s[pos] == 'E'){
        if (__builtin_popcountll(val*2) == 1) return;
        dfs(pos-1, val*2);
    }

}


int main(){
    cin >> s;

    for (int i=0; i<(int)s.size()-1; i++){
        if (s[i] == 'O' and s[i+1] == 'O'){
            cout << "INVALID\n";
            return 0;
        }
        if (s[i] != 'E' and s[i] != 'O'){
            cout << "INVALID\n";
            return 0;
        }
    }
    if (s.back() != 'O'){
        cout << "INVALID\n";
        return 0;
    }
    for (ll i = 0; i<=70; i++){
        ll aux = 1;
        dfs((int)s.size()-1,(aux << i));
        // cout << (aux << i) << endl;
        //cout << i << " " << resp << endl;
    }
    if (resp < 1e17){
        cout << resp << endl;
    }

    else cout << "INVALID\n";
    

}