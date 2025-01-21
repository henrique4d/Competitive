#include <bits/stdc++.h>
using namespace std;

set<int> colum;
set<int> row;
int resp = 0;

void backtracking(int pos, set<int> col, set<int> ro, set<int> press){
    if (pos == 5){
        if (col == colum and ro == row){
            resp++;
        }
        return;
    }
    
    backtracking(pos+1, col, ro, press);

    ro.insert((pos-1)/2);
    col.insert((pos-1)%2);
    press.insert(pos);

    backtracking(pos+1, col, ro, press);
    
}

void init(){
    colum.clear();
    row.clear();
    resp = 0;
}

void solve(){
    int n,m;
    cin >> n >> m;
    init();
    
    int x = 0;

    for (int i=0; i<m; i++){
        cin >> x;
        row.insert(x);
    }   
    for (int i=0; i<n; i++){
        cin >> x;
        colum.insert(x);
    }
    set<int> col;
    set<int> ro;
    set<int> pr;
 
    backtracking(1, col, ro, pr);
    cout << resp << endl;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}